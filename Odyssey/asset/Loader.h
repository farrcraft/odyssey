/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Asset.h"
#include "Type.h"

#include <boost/shared_ptr.hpp>

namespace odyssey::asset {
	/**
	 * The base interface for asset loaders
	 **/
	class Loader {
	public:
		/**
		 * Default constructor
		 * 
		 * @param Type t The asset type this loader provides
		 **/
		Loader(Type t);

		/**
		 * Get the asset type
		 * 
		 * @return Type
		 **/
		Type type() const;

		/**
		 * Load an asset
		 * 
		 * @param name The name of the asset to be loaded
		 **/
		virtual boost::shared_ptr<Asset> load(std::string_view name) = 0;

	private:
		Type type_;
	};
};
