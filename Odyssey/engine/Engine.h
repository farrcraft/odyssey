/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Logger.h"
#include "Player.h"

#include "../asset/Manager.h"
#include "../config/Bootstrap.h"
#include "../ui/Window.h"
#include "../render/Engine.h"

namespace odyssey::engine {

	/**
	 * This is the game engine.
	 * It is responsible for the main game loop
	 **/
	class Engine {
	public:
		/**
		 * @return bool
		 **/
		bool initialize();

		/**
		 * @return bool
		 **/
		bool run();

		/**
		 * @return bool
		 **/
		bool tick();

		/**
		 * @return bool
		 **/
		bool shutdown();

		/**
		 * @return Logger&
		 **/
		Logger& logger();

	private:
		odyssey::config::Bootstrap bootstrap_;
		boost::shared_ptr<odyssey::ui::Window> window_;
		Logger logger_;
		boost::shared_ptr<Player> player_;
		boost::shared_ptr<odyssey::render::Engine> renderEngine_;
		boost::shared_ptr<odyssey::asset::Manager> assetManager_;
	};

};
