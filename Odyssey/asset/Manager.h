/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Asset.h"
#include "Loader.h"
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
		Manager(const std::string& path);

		/**
		 **/
		boost::shared_ptr<Asset> load(const std::string& name, asset::Type t);

		/**
		 **/
		boost::shared_ptr<Asset> loadTypeFromExt(const std::string& name);

	protected:
		/**
		 **/
		boost::shared_ptr<Loader> resolveLoader(asset::Type t);

	private:
		boost::filesystem::path path_;
		std::unordered_map<asset::Type, boost::shared_ptr<Loader>> loaders_;
	};

};
