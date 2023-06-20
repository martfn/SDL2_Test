#pragma once
#include <SDL2/SDL.h>

namespace utils
{
	inline float hireTimeInSeconds()
	{
		float t = SDL_GetTicks(); // used to get delta time. asks SDL to retrieve the time (in ms) since the program started
		t *= 0.001f; // converts ms to s

		return t; // returns the final value
	}
}
