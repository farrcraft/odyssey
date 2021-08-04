/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Image.h"

#include <boost/shared_ptr.hpp>

namespace odyssey::image {

	class Reader {
	public:
		Reader();
		virtual ~Reader();

		virtual boost::shared_ptr<Image> read(const std::string& filename);

	private:

	};

}; // end namespace

