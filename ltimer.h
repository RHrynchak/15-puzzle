#pragma once
#include <SDL3/SDL.h>

class LTimer{
public:
    LTimer();
    void start();
    void stop();
    void pause();
    void unpause();
    Uint64 getTicks();
    bool isStarted() { return mStarted; }
    bool isPaused() { return mPaused; }
private:
    Uint64 mStartTicks = 0;
    Uint64 mPausedTicks = 0;
    bool mStarted = false;
    bool mPaused = false;
};