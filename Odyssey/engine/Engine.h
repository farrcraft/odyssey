/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../config/Bootstrap.h"
#include "Logger.h"

/**
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
	bool shutdown();

	/**
	 * @return Logger&
	 **/
	Logger& logger();

private:
	Bootstrap _bootstrap;
	Logger _logger;

};
