#pragma once
#include "ltimer.h"
#include "board.h"

class GameSession{
public:
    GameSession();
    static bool loadFont();
    static void deleteFont();
    bool isActive() const;
    void handleEvent( SDL_Event& e );
    int getMoves() const;
    Uint64 getTime() const;
    void restart();
    void show( SDL_Renderer* renderer ) const;
private:
    static TTF_Font* m_font;
    Direction m_direction;
    Board m_board { INITIAL_SHUFFLES };
    int m_moves = 0;
    LTimer m_timer;
};