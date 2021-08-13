/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../Loader.h"

namespace odyssey::asset::loader {
	/**
	 **/
	class Jpeg : public Loader {
	public:
		/**
		 **/
		Jpeg();

		/**
		 **/
		boost::shared_ptr<Asset> load(const std::string& name);
	};
};
