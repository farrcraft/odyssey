/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Window.h"

#include <iostream>

/**
 **/
Window::Window(Logger &logger) : 
	_window(nullptr),
	_surface(nullptr),
	_logger(logger) {

}

/**
**/
bool Window::create(int width, int height) {
	//Create window
	_window = SDL_CreateWindow("Odyssey", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (_window == NULL) {
		LOG_ERROR(_logger) << "Window could not be created! SDL_Error: " << SDL_GetError();
		return false;
	}
	// The surface contained by the window
	_surface = SDL_GetWindowSurface(_window);
	return true;
}

/**
 **/
void Window::destroy() {
	SDL_FreeSurface(_surface);
	SDL_DestroyWindow(_window);
}

/**
 **/
void Window::paint() {
	// Fill the surface white
	SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(_window);
}