/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Engine.h"

using namespace odyssey::render;

/**
 **/
Engine::Engine(odyssey::engine::Logger& logger) :
	logger_(logger),
	renderer_(nullptr) {

}

/**
 **/
Engine::~Engine() {

}

/**
 **/
bool Engine::initialize(boost::shared_ptr <odyssey::ui::Window> window) {
	window_ = window;
	renderer_ = SDL_CreateRenderer(window_->sdl(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (renderer_ == NULL) {
		return false;
	}
	return true;
}

/**
 **/
bool Engine::shutdown() {
	if (renderer_ != NULL) {
		SDL_DestroyRenderer(renderer_);
		renderer_ = NULL;
	}
	return true;
}

/**
 **/
void Engine::renderFrame() {
//	window_->paint(surface);

	SDL_RenderPresent(renderer_);
}

/**
 **/
void Engine::addRenderable(boost::shared_ptr <Renderable> renderable) {
	renderables_.push_back(renderable);
}
