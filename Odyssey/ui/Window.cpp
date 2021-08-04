/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Window.h"

#include <iostream>

using namespace odyssey::ui;

/**
 **/
Window::Window(odyssey::engine::Logger &logger) : 
	window_(nullptr),
	surface_(nullptr),
	logger_(logger) {

}

/**
**/
bool Window::create(int width, int height) {
	//Create window
	window_ = SDL_CreateWindow("Odyssey", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window_ == NULL) {
		LOG_ERROR(logger_) << "Window could not be created! SDL_Error: " << SDL_GetError();
		return false;
	}
	// The surface contained by the window
	surface_ = SDL_GetWindowSurface(window_);
	return true;
}

/**
 **/
void Window::destroy() {
	SDL_FreeSurface(surface_);
	SDL_DestroyWindow(window_);
}

/**
 **/
void Window::paint() {
	// Fill the surface white
	SDL_FillRect(surface_, NULL, SDL_MapRGB(surface_->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(window_);
}