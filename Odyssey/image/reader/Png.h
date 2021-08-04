/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "../Reader.h"

namespace odyssey::image::reader {

	class Png : public odyssey::image::Reader {
		public:
			Png();
			~Png();

			virtual boost::shared_ptr<Image> read(const std::string & filename);
	};

}; // end namespace
