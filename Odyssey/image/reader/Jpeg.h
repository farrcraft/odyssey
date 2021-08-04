/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once


#include "../Reader.h"

namespace odessey::image::reader {

	class Jpeg : public odessey::image::Reader
	{
	public:
		Jpeg();
		~Jpeg();

		virtual boost::shared_ptr<Image> read(const std::string& filename);
	};

}; // end namespace

