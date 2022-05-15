/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Device.h"
#include "KeyState.h"

namespace odyssey::input {
	/**
	 **/
	class Keyboard : public Device {
	public:
		/**
		 * @return bool true if the event was handled
		 **/
		bool handleEvent(const SDL_Event& event);

	private:
		KeyState state_;
	};
};
