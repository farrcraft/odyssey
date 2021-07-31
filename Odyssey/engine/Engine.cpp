/**
* 
**/

#include "Engine.h"

#include <iostream>
#include <SDL.h>

/**
**/
bool Engine::initialize() {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

/**
**/
bool Engine::shutdown() {
	// Quit SDL subsystems
	SDL_Quit();
	return true;
}
