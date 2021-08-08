/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include <SDL.h>

#include "Renderable.h"

#include "../engine/Logger.h"
#include "../ui/Window.h"

namespace odyssey::render {

	/**
	 * The render engine.
	 * This is different from the game engine.  While the game engine is responsible for coordinating the game,
	 * it is the responsibility of the render engine to manage the rendering pipeline.
	 **/
	class Engine {
	public:
		/**
		 **/
		Engine(odyssey::engine::Logger& logger);
		
		/**
		 **/
		~Engine();

		/**
		 **/
		bool initialize(boost::shared_ptr<odyssey::ui::Window> window);
		
		/**
		 **/
		bool shutdown();

		/**
		 **/
		void addRenderable(boost::shared_ptr<Renderable> renderable);

		/**
		 **/
		void renderFrame();

	private:
		boost::shared_ptr <odyssey::ui::Window> window_;
		odyssey::engine::Logger logger_;
		SDL_Renderer* renderer_;
		std::list<boost::shared_ptr<Renderable>> renderables_;
	};
};