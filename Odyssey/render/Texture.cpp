/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Texture.h"

using namespace odyssey::render;

/**
 **/
Texture::~Texture() {
	if (texture_ != NULL) {
		SDL_DestroyTexture(texture_);
		texture_ = NULL;
	}
}
