/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
**/

#include <SDL.h>

#include "Odyssey.h"
#include "engine/Engine.h"
#include "ui/Window.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

/**
**/
int main(int argc, char* argv[])
{
	Engine engine;
	if (!engine.initialize()) {
		return -1;
	}

	Window window;
	if (!window.create()) {
		return -1;
	}

	bool quit = false;
	SDL_Event e;

	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		window.paint();

		/*
		//Apply the image
		SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);

		//Wait two seconds
		SDL_Delay(2000);
		*/
	}

	window.destroy();

	if (!engine.shutdown()) {
		return -1;
	}

	return 0;
}
