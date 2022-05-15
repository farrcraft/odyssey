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
		Manager(std::string_view path);

		/**
		 **/
		boost::shared_ptr<Asset> load(std::string_view name, asset::Type t);

		/**
		 **/
		boost::shared_ptr<Asset> loadTypeFromExt(std::string_view name);

	protected:
		/**
		 **/
		boost::shared_ptr<Loader> resolveLoader(asset::Type t);

	private:
		boost::filesystem::path path_;
		std::unordered_map<asset::Type, boost::shared_ptr<Loader>> loaders_;
	};

};
