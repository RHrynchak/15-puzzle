#include "tile.h"
#include <cmath>
#include <string>

TTF_Font* Tile::m_font = nullptr;

Tile::Tile( int num ) : m_num(num) {}

bool Tile::loadFont(){
    bool success = true;
    m_font = TTF_OpenFont( "lazy.ttf", 72 );
    if ( m_font == nullptr ){
        SDL_Log( "Failed to load lazy font! SDL_ttf Error: %s\n", SDL_GetError() );
		success = false;
    }
    return success;
}

void Tile::deleteFont(){
    if ( m_font != nullptr ){
        TTF_CloseFont( m_font );
        m_font = nullptr;
    }
}

bool Tile::isEmpty() const { return m_num == 0; }

int Tile::getNum() const { return m_num; }

void Tile::display( SDL_Renderer* renderer, int x, int y, int width, int height ) const{
    if ( m_num == 0 ){
    }
    else 
    {
        float t = (float)m_num / 15.0f;
    
        SDL_Color color;
        const double PI = 3.14159265358979323846;
        color.r = (Uint8)(127 + 127 * sin(t * 2 * PI));
        color.g = (Uint8)(127 + 127 * sin(t * 2 * PI + 2 * PI / 3));
        color.b = (Uint8)(127 + 127 * sin(t * 2 * PI + 4 * PI / 3));
        color.a = 255;

        SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a );
        SDL_FRect frect { (float)x, (float)y, (float)width, (float)height };
        SDL_RenderFillRect( renderer, &frect );

        SDL_SetRenderDrawColor( renderer, 50, 50, 50, 255 );
        SDL_RenderRect( renderer, &frect );

        std::string numStr = std::to_string( m_num );
        SDL_Color textColor = {0, 0, 0, 255}; 
        SDL_Surface* textSurface = TTF_RenderText_Solid( m_font, numStr.c_str(), 0, textColor );
        if ( textSurface != nullptr ){
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
            if ( textTexture != nullptr ){
                int textWidth = textSurface->w;
                int textHeight = textSurface->h;
                int textX = x + (width - textWidth) / 2;
                int textY = y + (height - textHeight) / 2;
                SDL_FRect textRect = { (float)textX, (float)textY, (float)textWidth, (float)textHeight };
                SDL_RenderTexture( renderer, textTexture, nullptr, &textRect );
                SDL_DestroyTexture( textTexture );
            }
            SDL_DestroySurface( textSurface );
        }
    }
}