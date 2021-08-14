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
	logger_(logger),
	width_(300),
	height_(200) {

}

/**
**/
bool Window::create(int width, int height) {
	//Create window
	window_ = SDL_CreateWindow("Odyssey", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window_ == nullptr) {
		LOG_ERROR(logger_) << "Window could not be created! SDL_Error: " << SDL_GetError();
		return false;
	}
	// The surface contained by the window
	surface_ = SDL_GetWindowSurface(window_);

	// how do we keep these up to date when the window is resized?
	width_ = width;
	height_ = height;

	return true;
}

/**
 **/
void Window::destroy() {
	SDL_FreeSurface(surface_);
	surface_ = nullptr;
	SDL_DestroyWindow(window_);
	window_ = nullptr;
}

/**
 **/
SDL_Window* Window::sdl() {
	return window_;
}

int Window::width() const {
	return width_;
}

/**
 **/
int Window::height() const {
	return height_;
}

/**
 **/
void Window::paint(SDL_Surface *surface) {
	// passing in a surface here is just a temporary hack to quickly get an image on the screen
	SDL_BlitSurface(surface, nullptr, surface_, nullptr);

	/*
	we need to capture all of the things that we need to paint to the window here
	do we need to define a frame type?
	rendering is 2d but maybe there's a z-index that tells us in which order to do painting?
	what are painting primitives? sprites / surfaces / textures / images
	what about a paint operation type?
	*/
	// Fill the surface white
	// SDL_FillRect(surface_, NULL, SDL_MapRGB(surface_->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(window_);
}