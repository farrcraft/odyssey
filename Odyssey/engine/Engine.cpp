/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Engine.h"
#include "../ui/Window.h"

#include <SDL.h>

/**
 **/
bool Engine::initialize() {
	_logger.initialize();
	LOG_INFO(_logger) << "Initializing engine...";

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		LOG_ERROR(_logger) << "SDL could not initialize! SDL_Error: " << SDL_GetError();
		return false;
	}

	if (!_bootstrap.load(_logger)) {
		return false;
	}

	return true;
}

/**
 **/
bool Engine::shutdown() {
	LOG_INFO(_logger) << "Shutting down engine...";

	// Quit SDL subsystems
	SDL_Quit();
	return true;
}

/**
 **/
bool Engine::run() {
	Window window(_logger);
	if (!window.create(_bootstrap.windowWidth(), _bootstrap.windowHeight())) {
		return false;
	}

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
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
	return true;
}

/**
 **/
Logger& Engine::logger() {
	return _logger;
}
