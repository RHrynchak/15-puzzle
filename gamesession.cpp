#include "gamesession.h"

GameSession::GameSession(){
    m_timer.start();
}

bool GameSession::isActive() { return !m_timer.isPaused(); }
bool GameSession::isPaused() { return m_timer.isPaused(); }
bool GameSession::isOver() { return m_board.isSolved(); }

int GameSession::getMoves() { return m_moves; }
Uint64 GameSession::getTime() { return m_timer.getTicks(); }

void GameSession::pause() { m_timer.pause(); }
void GameSession::unpause() { m_timer.unpause(); }

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
        }
    }
}

void GameSession::show( SDL_Renderer* renderer ){
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
    m_board.display( renderer );
    SDL_RenderPresent( renderer );
}
