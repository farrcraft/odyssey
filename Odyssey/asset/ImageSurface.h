/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Asset.h"

#include <SDL.h>

namespace odyssey::asset {
	/**
	 **/
	class ImageSurface : public Asset {
	public:
		/**
		 **/
		ImageSurface(odyssey::engine::Logger& logger, const std::string& name, Type t);

		/**
		 **/
		~ImageSurface();

		/**
		 **/
		bool load(const std::string& path);

	private:
		SDL_Surface* surface_;
	};
};
