#include "gamesession.h"
#include <string>

TTF_Font* GameSession::m_font = nullptr;

bool GameSession::loadFont(){
    bool success = true;
    m_font = TTF_OpenFont( "lazy.ttf", 40 );
    if ( m_font == nullptr ){
        SDL_Log( "Failed to load lazy font! SDL_ttf Error: %s\n", SDL_GetError() );
		success = false;
    }
    return success;
}

GameSession::GameSession(){
    m_timer.start();
}

bool GameSession::isActive() { return !m_timer.isPaused(); }
bool GameSession::isOver() { return m_board.isSolved(); }

int GameSession::getMoves() { return m_moves; }
Uint64 GameSession::getTime() { return m_timer.getTicks(); }

void GameSession::handleEvent( SDL_Event& e ){
    if ( e.type == SDL_EVENT_KEY_DOWN ) {
        switch ( e.key.key ){
        case SDLK_W:
        case SDLK_UP:
            m_direction.changeType( Direction::Type::UP );
            break;
        case SDLK_S:
        case SDLK_DOWN:
            m_direction.changeType( Direction::Type::DOWN );
            break;
        case SDLK_A:
        case SDLK_LEFT:
            m_direction.changeType( Direction::Type::LEFT );
            break;
        case SDLK_D:
        case SDLK_RIGHT:
            m_direction.changeType( Direction::Type::RIGHT );
            break;
        }
        bool changed = m_board.moveTiles( m_direction );
        if ( changed ){
            ++m_moves;
            if ( m_board.isSolved() ){
                m_timer.pause();
            }
        }
    }
}

void GameSession::show( SDL_Renderer* renderer ){
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
    m_board.display( renderer );

    std::string moveString = "Moves used:" + std::to_string( m_moves );
    SDL_Color textColor = {0, 0, 0, 255}; 
    SDL_Surface* textSurface = TTF_RenderText_Solid( m_font, moveString.c_str(), 0, textColor );
    if ( textSurface != nullptr ){
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if ( textTexture != nullptr ){
            int textWidth = textSurface->w;
            int textHeight = textSurface->h;
            int textX = ( SCREEN_WIDTH + m_board.getWidth() - textWidth ) / 2;
            int textY = ( m_board.getHeight() / m_board.getSize() );
            SDL_FRect textRect = { (float)textX, (float)textY, (float)textWidth, (float)textHeight };
            SDL_RenderTexture( renderer, textTexture, nullptr, &textRect );
            SDL_DestroyTexture( textTexture );
        }
        SDL_DestroySurface( textSurface );
    }

    std::string timeString = "Time passed:\n";
    std::string secondsPassed = std::to_string( m_timer.getTicks() / 1000 );
    for ( int i = 0; i < 5 - (secondsPassed.length() -1 ) / 2; ++i){
        timeString += " ";
    }
    timeString += secondsPassed;
    textColor = {0, 0, 0, 255}; 
    textSurface = TTF_RenderText_Solid_Wrapped( m_font, timeString.c_str(), 0, textColor, 0 );
    if ( textSurface != nullptr ){
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if ( textTexture != nullptr ){
            int textWidth = textSurface->w;
            int textHeight = textSurface->h;
            int textX = ( SCREEN_WIDTH + m_board.getWidth() - textWidth ) / 2;
            int textY = ( SCREEN_HEIGHT - m_board.getHeight() / m_board.getSize() ) - textHeight;
            SDL_FRect textRect = { (float)textX, (float)textY, (float)textWidth, (float)textHeight };
            SDL_RenderTexture( renderer, textTexture, nullptr, &textRect );
            SDL_DestroyTexture( textTexture );
        }
        SDL_DestroySurface( textSurface );
    }

    SDL_RenderPresent( renderer );
}

void GameSession::restart(){
    m_board = Board(INITIAL_SHUFFLES);
    m_moves = 0;
    m_timer.stop();
    m_timer.start();
}
