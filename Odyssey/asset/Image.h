/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Asset.h"
#include "../image/Image.h"

#include <boost/shared_ptr.hpp>

namespace odyssey::asset {
	/**
	 **/
	class Image : public Asset {
	public:
		/**
		 **/
		Image(const std::string& name, Type t, boost::shared_ptr<odyssey::image::Image> img);

		/**
		 **/
		boost::shared_ptr<odyssey::image::Image> image();

	private:
		boost::shared_ptr<odyssey::image::Image> image_;
	};
};
