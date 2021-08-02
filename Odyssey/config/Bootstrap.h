/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../engine/Logger.h"

#include <string>

class Bootstrap {
public:
	/**
	* @param Logger* logger
	* @return bool
	 **/
	bool load(Logger* logger);

private:
	std::string _dataPath;
};
