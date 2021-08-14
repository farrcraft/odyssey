/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Engine.h"

#include <boost/make_shared.hpp>

using namespace odyssey::render;

/**
 **/
Engine::Engine(odyssey::engine::Logger& logger, boost::shared_ptr<odyssey::asset::Manager> assetManager) :
	logger_(logger),
	assetManager_(assetManager) {
	textureCache_ = boost::make_shared<TextureCache>();
}

/**
 **/
Engine::~Engine() {

}

/**
 **/
bool Engine::initialize(boost::shared_ptr <odyssey::ui::Window> window) {
	window_ = window;
	context_ = boost::make_shared<Context>(window_);
	scene_ = boost::make_shared<Scene>(context_);
	backBuffer_ = boost::make_shared<Texture>(context_, window_->width(), window_->height());

	return true;
}

/**
 **/
bool Engine::shutdown() {

	return true;
}

/**
 **/
void Engine::renderFrame() {
	boost::shared_ptr<Frame> frame = scene_->collect();
	frame->draw();

	// flip backbuffer
	SDL_RenderClear(context_->handle());
	SDL_RenderCopyEx(context_->handle(), backBuffer_->tex(), NULL, NULL, 0, NULL, SDL_FLIP_VERTICAL);
	SDL_RenderPresent(context_->handle());
}

/**
 **/
boost::shared_ptr<odyssey::asset::Manager> Engine::assetManager() {
	return assetManager_;
}

/**
 **/
boost::shared_ptr<TextureCache> Engine::textureCache() {
	return textureCache_;
}

/**
 **/
boost::shared_ptr<Context> Engine::context() {
	return context_;
}

/**
 **/
boost::shared_ptr<Texture> Engine::backBuffer() {
	return backBuffer_;
}

/**
 **/
boost::shared_ptr<Scene> Engine::scene() {
	return scene_;
}
