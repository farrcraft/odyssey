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
		Texture(SDL_Renderer* renderer, SDL_Surface* surface);

		/**
		 **/
		Texture(SDL_Renderer* renderer, int width, int height);

		/**
		 **/
		~Texture();

	private:
		SDL_Texture* texture_;
	};

};
