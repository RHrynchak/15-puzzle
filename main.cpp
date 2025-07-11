#include "gamesession.h"

bool init();
void close();

SDL_Window* gWindow;
SDL_Renderer* gRenderer;

bool init(){
    bool success = true;
    if ( !SDL_Init(SDL_INIT_VIDEO) ) {
        SDL_Log( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else{
        if ( !SDL_CreateWindowAndRenderer( "Hello SDL", SCREEN_WIDTH, SCREEN_HEIGHT, 0, &gWindow, &gRenderer ) ) {
            SDL_Log( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else {
            SDL_SetRenderVSync( gRenderer, 1 );
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            if ( !TTF_Init() ){
				SDL_Log( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", SDL_GetError() );
				success = false;
			}
        }
    }
    return success;
}

void close(){
    Tile::deleteFont();
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gRenderer = nullptr;
    gWindow = nullptr;
    SDL_Quit();
}

int main(){
    if ( !init() || !Tile::loadFont() ){
        SDL_Log( "Failed to initialize!\n" );
    }
    else{
        bool quit = false;
        SDL_Event e;
        GameSession session;
        while ( !quit ){
            while ( SDL_PollEvent( &e ) ){
                if ( e.type == SDL_EVENT_QUIT ){
                    quit = true;
                    SDL_Log( "\n\nBye!\n\n" );
                }
                session.handleEvent(e);
                if ( session.isOver() ){
                    quit = true;
                }
            }
            session.show( gRenderer );
            if ( quit == true ){
                SDL_Delay(500);
            }
        }
    }
    close();
    return 0;
}