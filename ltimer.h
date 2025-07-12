#pragma once
#include <SDL3/SDL.h>

class LTimer{
public:
    LTimer();
    void start();
    void stop();
    void pause();
    void unpause();
    Uint64 getTicks() const;
    bool isStarted() const { return mStarted; }
    bool isPaused() const { return mPaused; }
private:
    Uint64 mStartTicks = 0;
    Uint64 mPausedTicks = 0;
    bool mStarted = false;
    bool mPaused = false;
};