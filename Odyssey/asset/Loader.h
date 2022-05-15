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
	 **/
	class Loader {
	public:
		/**
		 **/
		Loader(Type t);

		/**
		 **/
		Type type() const;

		/**
		 **/
		virtual boost::shared_ptr<Asset> load(std::string_view name) = 0;

	private:
		Type type_;
	};
};
