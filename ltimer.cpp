#include "ltimer.h"

LTimer::LTimer(){}

void LTimer::start(){
    mStarted = true;
    mPaused = false;
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void LTimer::stop(){
    mStarted = false;
    mPaused = false;
    mStartTicks = 0;
    mPausedTicks = 0;
}

void LTimer::pause(){
    if ( mStarted && !mPaused ){
        mPaused = true;
        mPausedTicks = SDL_GetTicks() - mStartTicks;
        mStartTicks = 0;
    }
}

void LTimer::unpause(){
    if ( mStarted && mPaused ){
        mPaused = false;
        mStartTicks = SDL_GetTicks() - mPausedTicks;
        mPausedTicks = 0;
    }
}

Uint64 LTimer::getTicks() const {
    Uint64 time = 0;
    if ( mStarted ){
        if ( mPaused ){
            time = mPausedTicks;
        }
        else{
            time = SDL_GetTicks() - mStartTicks;
        }
    }
    return time;
}