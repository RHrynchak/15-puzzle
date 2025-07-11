#pragma once
#include "ltimer.h"
#include "board.h"

class GameSession{
public:
    GameSession();
    static bool loadFont();
    bool isActive();
    bool isOver();
    void handleEvent( SDL_Event& e );
    int getMoves();
    Uint64 getTime();
    void restart();
    void show( SDL_Renderer* renderer );
private:
    static TTF_Font* m_font;
    Direction m_direction;
    Board m_board { INITIAL_SHUFFLES };
    int m_moves = 0;
    LTimer m_timer;
};