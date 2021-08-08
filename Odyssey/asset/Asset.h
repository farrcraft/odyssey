/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Type.h"
#include "../engine/Logger.h"

#include <boost/filesystem.hpp>

#include <string>

namespace odyssey::asset {
	/**
	 **/
	class Asset {
	public:
		/**
		 **/
		Asset(odyssey::engine::Logger& logger, const std::string& name, asset::type::Type t);

	protected:
		odyssey::engine::Logger logger_;
		std::string name_;
		asset::type::Type type_;
		boost::filesystem::path path_;
	};
};
