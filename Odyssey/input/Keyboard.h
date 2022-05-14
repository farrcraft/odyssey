/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include <SDL.h>

#include "Device.h"

namespace odyssey::input {
	/**
	 **/
	class Keyboard : public Device {
	public:
		bool handleEvent(const SDL_Event& event);
	};
};
