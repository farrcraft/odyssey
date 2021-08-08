/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../Renderable.h"
#include "../../engine/Player.h"

namespace odyssey::render::renderable {
	/**
	 **/
	class Player : public Renderable {
	public:
		/**
		 **/
		Player(odyssey::engine::Logger& logger, boost::shared_ptr<odyssey::engine::Player> player);

		/**
		 **/
		bool draw();

	private:
		boost::shared_ptr<odyssey::engine::Player> player_;
	};
};
