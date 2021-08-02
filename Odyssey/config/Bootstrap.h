/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../engine/Logger.h"

#include <string>

/**
 * Bootstrap configuration
 * This is a minimal configuration file that provides the core settings 
 * necessary for booting up the engine.
 **/
class Bootstrap {
public:
	/**
	 **/
	Bootstrap();

	/**
	 * @param Logger& logger
	 * @return bool
	 **/
	bool load(Logger& logger);

	/**
	 **/
	int windowWidth() const;

	/**
	 **/
	int windowHeight() const;

private:
	std::string _dataPath;
	int _windowWidth;
	int _windowHeight;
};
