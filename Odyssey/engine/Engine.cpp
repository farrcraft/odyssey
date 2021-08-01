/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
**/

#include "Engine.h"

#include <iostream>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>

#include <SDL.h>

/**
 **/
bool Engine::initialize() {
	// Setup logging
	boost::log::add_file_log(
		boost::log::keywords::file_name = "odyssey_%N.log",                                        /*< file name pattern >*/
		boost::log::keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
		boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
		boost::log::keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
	);
	boost::log::core::get()->set_filter(
		boost::log::trivial::severity >= boost::log::trivial::info
	);
	boost::log::add_common_attributes();

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	if (!_bootstrap.load()) {
		return false;
	}

	return true;
}

/**
 **/
bool Engine::shutdown() {
	// Quit SDL subsystems
	SDL_Quit();
	return true;
}
