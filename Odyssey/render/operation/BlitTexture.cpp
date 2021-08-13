/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "BlitTexture.h"

using namespace odyssey::render;
using namespace odyssey::render::operation;

/**
 **/
BlitTexture::BlitTexture(boost::shared_ptr<Texture> source, boost::shared_ptr<Texture> destination) :
	source_(source),
	destination_(destination) {

}

/**
 **/
bool BlitTexture::run(boost::shared_ptr<Context> context) {
	//Now render to the texture
	SDL_SetRenderTarget(context->handle(), destination_->tex());
	SDL_RenderClear(context->handle());
	SDL_RenderCopy(context->handle(), source_->tex(), NULL, NULL);
	//Detach the texture
	SDL_SetRenderTarget(context->handle(), NULL);

	return true;
}
