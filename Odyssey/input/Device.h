/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include <SDL.h>

namespace odyssey::input {
	/**
	 **/
	class Device {
	public:
		virtual bool handleEvent(const SDL_Event& event) = 0;
	};
};
