/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Type.h"

#include <string>

namespace odyssey::asset {
	/**
	 **/
	class Asset {
	public:
		/**
		 **/
		Asset(std::string_view name, Type t);

	protected:
		std::string_view name_;
		Type type_;
	};
};
