/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Context.h"
#include "Operation.h"
#include "Renderable.h"
#include "Scene.h"
#include "TextureCache.h"

#include "../engine/Logger.h"
#include "../asset/Manager.h"
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
		Engine(odyssey::engine::Logger& logger, boost::shared_ptr<odyssey::asset::Manager> assetManager);
		
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
		boost::shared_ptr<odyssey::asset::Manager> assetManager();
		
		/**
		 **/
		boost::shared_ptr<TextureCache> textureCache();

		/**
		 **/
		void renderFrame();

		/**
		 **/
		boost::shared_ptr<Context> context();

		/**
		 **/
		boost::shared_ptr<Texture> backBuffer();

		/**
		 **/
		boost::shared_ptr<Scene> scene();

	private:
		boost::shared_ptr <odyssey::ui::Window> window_;
		boost::shared_ptr<Context> context_;
		odyssey::engine::Logger logger_;
		boost::shared_ptr<Texture> backBuffer_;
		boost::shared_ptr<odyssey::asset::Manager> assetManager_;
		std::list<boost::shared_ptr<Renderable>> renderables_;
		boost::shared_ptr<TextureCache> textureCache_;
		boost::shared_ptr<Scene> scene_;
	};
};