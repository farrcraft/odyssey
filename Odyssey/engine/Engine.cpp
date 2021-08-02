/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Engine.h"

#include <SDL.h>

/**
 **/
bool Engine::initialize() {
	_logger.initialize();
	BOOST_LOG_SEV(_logger.get(), boost::log::trivial::info) << "Initializing engine...";

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		BOOST_LOG_SEV(_logger.get(), boost::log::trivial::error) << "SDL could not initialize! SDL_Error: " << SDL_GetError();
		return false;
	}

	if (!_bootstrap.load(&_logger)) {
		return false;
	}

	return true;
}

/**
 **/
bool Engine::shutdown() {
	BOOST_LOG_SEV(_logger.get(), boost::log::trivial::info) << "Shutting down engine...";

	// Quit SDL subsystems
	SDL_Quit();
	return true;
}

/**
 **/
Logger* Engine::logger() {
	return &_logger;
}
