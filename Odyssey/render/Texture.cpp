/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Texture.h"

using namespace odyssey::render;

/**
 **/
Texture::Texture(boost::shared_ptr<Context> context, SDL_Surface* surface) :
	context_(context) {
	texture_ = SDL_CreateTextureFromSurface(context_->handle(), surface);
}

/**
 **/
Texture::Texture(boost::shared_ptr<Context> context, int width, int height) :
	context_(context) {
	texture_ = SDL_CreateTexture(context_->handle(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
}

/**
 **/
Texture::~Texture() {
	if (texture_ != NULL) {
		SDL_DestroyTexture(texture_);
		texture_ = NULL;
	}
}

/**
 **/
SDL_Texture* Texture::tex() {
	return texture_;
}
