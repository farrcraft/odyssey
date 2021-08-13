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
		Asset(const std::string& name, Type t);

	protected:
		std::string name_;
		Type type_;
	};
};
