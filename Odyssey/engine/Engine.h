/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
**/

#pragma once

#include "../config/Bootstrap.h"

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
	bool shutdown();

private:
	Bootstrap _bootstrap;
};
