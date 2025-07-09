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
    for ( int i = 0; i < 5; ++i ){
        std::cout << Direction::getRandomDirection() << std::endl;
    }
    std::cout << std::boolalpha;
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::UP)    == Point{ 1, 0 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::DOWN)  == Point{ 1, 2 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::LEFT)  == Point{ 0, 1 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::RIGHT) == Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 1, 2 }) << '\n';
    std::cout << !(Point{ 1, 1 } != Point{ 1, 1 }) << '\n';

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
                        direction.changeDirection( Direction::Type::UP );
                        std::cout << direction.getDirection() << std::endl;
                        SDL_Log( "Valid command: up" );
                        break;
                    case SDLK_S:
                        direction.changeDirection( Direction::Type::DOWN );
                        std::cout << direction.getDirection() << std::endl;
                        SDL_Log( "Valid command: down" );
                        break;
                    case SDLK_A:
                        direction.changeDirection( Direction::Type::LEFT );
                        std::cout << direction.getDirection() << std::endl;
                        SDL_Log( "Valid command: left" );
                        break;
                    case SDLK_D:
                        direction.changeDirection( Direction::Type::RIGHT );
                        std::cout << direction.getDirection() << std::endl;
                        SDL_Log( "Valid command: right" );
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