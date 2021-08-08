/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Asset.h"
#include "Type.h"

#include "../engine/Logger.h"

#include <boost/filesystem.hpp>

namespace odyssey::asset {
	/**
	 **/
	class Manager {
	public:
		/**
		 **/
		Manager(odyssey::engine::Logger& logger, const std::string& path);
		
		/**
		 **/
		bool load(const std::string& name, asset::Type t);

	private:
		odyssey::engine::Logger logger_;
		boost::filesystem::path path_;
		std::list<boost::shared_ptr<Asset>> assets_;
	};

};
