/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../engine/Logger.h"

#include <SDL.h>

namespace odyssey::ui {

	/**
	**/
	class Window {
	public:
		/**
		 * @param Logger* logger
		 **/
		Window(odyssey::engine::Logger& logger);

		/**
		 * @return bool
		 **/
		bool create(int width, int height);

		/**
		 * @return void
		 **/
		void destroy();

		/**
		 **/
		SDL_Window* sdl();

		/**
		**/
		void paint(SDL_Surface *surface);

	private:
		SDL_Window* window_;
		SDL_Surface* surface_;
		odyssey::engine::Logger logger_;
	};

};
