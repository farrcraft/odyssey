/**
**/

#include "Window.h"

#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

/**
**/
bool Window::create() {
	//Create window
	_window = SDL_CreateWindow("Odyssey", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (_window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	// The surface contained by the window
	_surface = SDL_GetWindowSurface(_window);
	return true;
}

/**
**/
bool Window::destroy() {
	SDL_FreeSurface(_surface);
	SDL_DestroyWindow(_window);

	return true;
}

/**
**/
void Window::paint() {
	// Fill the surface white
	SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(_window);
}