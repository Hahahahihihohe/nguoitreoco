#include "SDLL.h"
Timer* Timer::sInstance = NULL;
Timer::Timer() {
	reset();
	
}
Timer* Timer::Instance() {
	if (sInstance == NULL) {
		sInstance = new Timer();
	}
	return sInstance;
}
void Timer::release() {
	delete sInstance;
	sInstance = NULL;
}
void Timer::reset() {
	mStart_Ticks = SDL_GetTicks();
	Beta_Time = 0;
	mElapsed_Ticks = 0;
	
}
int Timer::Delta_Time() {
	return Delata_Time - Beta_Time;
}
void Timer::pausing() {
	Alpha_Time = (SDL_GetTicks() - temp_timer)*0.001;
}
void Timer::update() {
	mElapsed_Ticks = SDL_GetTicks() - mStart_Ticks;
	Delata_Time = mElapsed_Ticks * 0.001;
	if (pause) {
		temp_timer = SDL_GetTicks();
	}
}

