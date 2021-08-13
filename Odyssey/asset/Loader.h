/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
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
		virtual boost::shared_ptr<Asset> load(const std::string& name) = 0;

	private:
		Type type_;
	};
};
