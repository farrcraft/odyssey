/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include <SDL.h>

namespace odyssey::render {
	/**
	 * Represents an SDL Texture
	 **/
	class Texture {
	public:
		/**
		 * Create a texture from a surface 
		 **/
		Texture(SDL_Renderer* renderer, SDL_Surface* surface);

		/**
		 * Create an empty texture with given dimensions 
		 **/
		Texture(SDL_Renderer* renderer, int width, int height);

		/**
		 **/
		~Texture();

	private:
		SDL_Texture* texture_;
	};

};
