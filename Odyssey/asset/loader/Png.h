/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../Loader.h"

namespace odyssey::asset::loader {
	/**
	 **/
	class Png : public Loader {
	public:
		/**
		 **/
		Png();

		/**
		 **/
		boost::shared_ptr<Asset> load(std::string_view name);
	};
};
