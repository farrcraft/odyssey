/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Frame.h"

#include "../engine/Logger.h"

namespace odyssey::render {
	/**
	 * Forward declaration 
	 **/
	class Engine;

	/**
	 **/
	class Renderable {
	public:
		/**
		 **/
		Renderable(boost::shared_ptr<Engine> renderer);

		/**
		 **/
		virtual bool draw(boost::shared_ptr<Frame> frame);

	protected:
		boost::shared_ptr<odyssey::render::Engine> renderer_;
	};
};
