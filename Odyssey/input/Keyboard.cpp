/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#include "Keyboard.h"

using namespace odyssey::input;

bool Keyboard::handleEvent(const SDL_Event& event) {
	switch (event.type) {
	case SDL_KEYDOWN:
		break;
	case SDL_KEYUP:
		break;
	default:
		return false;
	}
	return true;
}