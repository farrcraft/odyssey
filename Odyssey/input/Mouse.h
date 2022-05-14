/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Device.h"

#include <SDL.h>

namespace odyssey::input {
	/**
	 **/
	class Mouse : public Device {
	public:
		bool handleEvent(const SDL_Event& event);
	};
};
