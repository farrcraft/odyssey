/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Renderable.h"

using namespace odyssey::render;

/**
 **/
Renderable::Renderable(odyssey::engine::Logger& logger) : 
	logger_(logger),
	renderer_(nullptr) {
}

/**
 **/
bool Renderable::initialize(SDL_Renderer* renderer) {
	renderer_ = renderer;
	return true;
}

/**
 **/
bool Renderable::draw() {
	return true;
}
