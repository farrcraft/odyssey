/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Asset.h"

#include <boost/json.hpp>
#include <boost/shared_ptr.hpp>

namespace odyssey::asset {
	/**
	 **/
	class Json : public Asset {
	public:
		/**
		 **/
		Json(std::string_view name, Type t, const boost::json::object &doc);

		/**
		 **/
		boost::json::object const& document();

	private:
		boost::json::object document_;
	};
};