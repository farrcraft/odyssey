/**
**/

#pragma once

#include <SDL.h>

/**
**/
class Window {
public:
	/**
	* @return bool
	**/
	bool create();

	/**
	* @return bool
	**/
	bool destroy();

	/**
	**/
	void paint();

private:
	SDL_Window* _window;
	SDL_Surface* _surface;
};
