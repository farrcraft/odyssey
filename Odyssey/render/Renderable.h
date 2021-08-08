/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../engine/Logger.h"

#include <SDL.h>

namespace odyssey::render {
	/**
	 **/
	class Renderable {
	public:
		/**
		 **/
		Renderable(odyssey::engine::Logger& logger);

		/**
		 **/
		virtual bool initialize(SDL_Renderer* renderer);

		/**
		 **/
		virtual bool draw();

	protected:
		odyssey::engine::Logger logger_;
		SDL_Renderer* renderer_;
	};
};
