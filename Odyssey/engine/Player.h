/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Sprite.h"

#include <glm/vec2.hpp>

namespace odyssey::engine {
	/**
	 * 
	 **/
	class Player {
	public:
		/**
		 **/
		Player();

		/**
		 **/
		bool tick();

		/**
		 **/
		void move(int x, int y);

		/**
		 **/
		glm::ivec2 position() const;

	private:
		glm::ivec2 position_;
		Sprite sprite_;
	};
};
