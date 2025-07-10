#pragma once
#include "SDL3/SDL.h"
#include <SDL3_ttf/SDL_ttf.h>

class Tile{
public:
    Tile() = default;
    explicit Tile( int num );
    static bool loadFont();
    static void deleteFont();
    bool isEmpty() const;
    int getNum() const;
    void display( SDL_Renderer* renderer, int x, int y, int width, int height ) const;
private:
    static TTF_Font* m_font;
    int m_num;
};