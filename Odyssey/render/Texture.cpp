/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Texture.h"

using namespace odyssey::render;

/**
 **/
Texture::Texture(SDL_Renderer* renderer, SDL_Surface* surface) {
	texture_ = SDL_CreateTextureFromSurface(renderer, surface);
}

/**
 **/
Texture::Texture(SDL_Renderer* renderer, int width, int height) {
	texture_ = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
}

/**
 **/
Texture::~Texture() {
	if (texture_ != NULL) {
		SDL_DestroyTexture(texture_);
		texture_ = NULL;
	}
}
