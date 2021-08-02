/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../engine/Logger.h"

#include <SDL.h>

/**
**/
class Window {
public:
	/**
	 * @param Logger* logger
	 **/
	Window(Logger* logger);

	/**
	 * @return bool
	 **/
	bool create();

	/**
	 * @return void
	 **/
	void destroy();

	/**
	**/
	void paint();

private:
	SDL_Window* _window;
	SDL_Surface* _surface;
	Logger* _logger;
};
