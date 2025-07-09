#include "board.h"
#include "constants.h"
#include "direction.h"
#include "point.h"
#include <SDL3/SDL.h>
#include <iostream>

bool init();
void close();

SDL_Window* gWindow;
SDL_Renderer* gRenderer;

bool init(){
    bool success = true;
    if ( !SDL_Init( SDL_INIT_VIDEO ) ){
        SDL_Log( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else{
        if ( !SDL_CreateWindowAndRenderer( "Hello SDL", SCREEN_WIDTH, SCREEN_HEIGHT, 0, &gWindow, &gRenderer ) ) {
            SDL_Log( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else {
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        }
    }
    return success;
}

void close(){
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gRenderer = nullptr;
    gWindow = nullptr;
    SDL_Quit();
}

int main(){
    Board board{};
    board.display();

    if ( !init() ){
        SDL_Log( "Failed to initialize!\n" );
    }
    else{
        bool quit = false;
        SDL_Event e;
        Direction direction;
        while ( !quit ){
            while ( SDL_PollEvent( &e ) ){
                if ( e.type == SDL_EVENT_QUIT ){
                    quit = true;
                    SDL_Log( "\n\nBye!\n\n" );
                }
                else if ( e.type == SDL_EVENT_KEY_DOWN ) {
                    switch ( e.key.key ){
                    case SDLK_W:
                        direction.changeType( Direction::Type::UP );
                        board.moveTiles( direction );
                        board.display();
                        break;
                    case SDLK_S:
                        direction.changeType( Direction::Type::DOWN );
                        board.moveTiles( direction );
                        board.display();
                        break;
                    case SDLK_A:
                        direction.changeType( Direction::Type::LEFT );
                        board.moveTiles( direction );
                        board.display();
                        break;
                    case SDLK_D:
                        direction.changeType( Direction::Type::RIGHT );
                        board.moveTiles( direction );
                        board.display();
                        break;
                    }
                }
            }
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			SDL_RenderClear( gRenderer );
            SDL_RenderPresent( gRenderer );
        }
    }
    close();
    return 0;
}