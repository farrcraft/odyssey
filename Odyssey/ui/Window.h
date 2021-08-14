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
		 * Paint a surface onto the window.
		 * Typically this isn't used and texture rendering is done instead.
		 **/
		void paint(SDL_Surface *surface);

		/**
		 **/
		void resize(int width, int height);

		/**
		 **/
		int width() const;

		/**
		 **/
		int height() const;

	private:
		SDL_Window* window_;
		SDL_Surface* surface_;
		int width_;
		int height_;
		odyssey::engine::Logger logger_;
	};

};
