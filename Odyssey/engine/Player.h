/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Sprite.h"

namespace odyssey::engine {
	/**
	 * 
	 **/
	class Player {
	public:
		/**
		 **/
		bool tick();

	private:
		Sprite sprite_;
	};
};
