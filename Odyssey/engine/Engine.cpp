/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Engine.h"
#include "../ui/Window.h"

#include <SDL.h>

using namespace odyssey::engine;

/**
 **/
bool Engine::initialize() {
	logger_.initialize();
	LOG_INFO(logger_) << "Initializing engine...";

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		LOG_ERROR(logger_) << "SDL could not initialize! SDL_Error: " << SDL_GetError();
		return false;
	}

	if (!bootstrap_.load(logger_)) {
		return false;
	}

	return true;
}

/**
 **/
bool Engine::shutdown() {
	LOG_INFO(logger_) << "Shutting down engine...";

	// Quit SDL subsystems
	SDL_Quit();
	return true;
}

/**
 **/
bool Engine::run() {
	odyssey::ui::Window window(logger_);
	if (!window.create(bootstrap_.windowWidth(), bootstrap_.windowHeight())) {
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
	return logger_;
}
