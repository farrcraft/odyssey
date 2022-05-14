/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Engine.h"

#include "../render/renderable/Player.h"

#include <boost/filesystem.hpp>
#include <boost/make_shared.hpp>

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

	// Load bootstrap config
	if (!bootstrap_.load(logger_)) {
		return false;
	}
	
	assetManager_ = boost::make_shared<odyssey::asset::Manager>(bootstrap_.dataPath());

	player_ = boost::make_shared<Player>(registry_);

	return true;
}

/**
 **/
bool Engine::shutdown() {
	LOG_INFO(logger_) << "Shutting down engine...";

	window_->destroy();

	// Quit SDL subsystems
	SDL_Quit();
	return true;
}

/**
 **/
bool Engine::run() {
	window_ = boost::make_shared<odyssey::ui::Window>(logger_);
	if (!window_->create(bootstrap_.windowWidth(), bootstrap_.windowHeight())) {
		return false;
	}

	renderEngine_ = boost::make_shared<odyssey::render::Engine>(logger_, assetManager_);
	if (!renderEngine_->initialize(window_)) {
		return false;
	}

	bool quit = false;
	SDL_Event event;

	renderEngine_->scene()->setPlayer(boost::make_shared<odyssey::render::renderable::Player>(renderEngine_, player_));

	// Enter main game loop
	while (!quit) {
		// Handle events on queue
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_WINDOWEVENT:
				switch (event.window.event) {
				case SDL_WINDOWEVENT_RESIZED:
					renderEngine_->resize(event.window.data1, event.window.data2);
					break;
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					renderEngine_->resize(event.window.data1, event.window.data2);
					break;
				case SDL_WINDOWEVENT_FOCUS_LOST:
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					break;
				}
				break;
			default:
				inputEngine_->filterEvent(event);
			}
		}

		// tick the game
		if (!tick()) {
			return false;
		}

		// and draw the image on the screen
		renderEngine_->renderFrame();
	}

	return true;
}

/**
 **/
bool Engine::tick() {

	// Tick various systems, e.g. Movement System, Collision System, Combat System, etc

	return true;
}

/**
 **/
Logger& Engine::logger() {
	return logger_;
}
