/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include <SDL.h>

namespace odyssey::render {
	/**
	 **/
	class Texture {
	public:
		/**
		 **/
		~Texture();

	private:
		SDL_Texture* texture_;
	};

};
