#pragma once
#include "ltimer.h"
#include "board.h"

class GameSession{
public:
    GameSession();
    bool isActive();
    bool isPaused();
    bool isOver();
    void handleEvent( SDL_Event& e );
    int getMoves();
    Uint64 getTime();
    //void restart();
    void pause();
    void unpause();
    void show( SDL_Renderer* renderer );
private:
    Direction m_direction;
    Board m_board { INITIAL_SHUFFLES };
    int m_moves = 0;
    LTimer m_timer;
};