/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Jpeg.h"
#include "../Image.h"
#include "../../image/reader/Jpeg.h"

#include <boost/make_shared.hpp>

using namespace odyssey::asset;
using namespace odyssey::asset::loader;

/**
 **/
Jpeg::Jpeg() : Loader(Type::IMAGE_JPEG) {

}

/**
 **/
boost::shared_ptr<Asset> Jpeg::load(const std::string& name) {
	odyssey::image::reader::Jpeg reader;
	boost::shared_ptr<odyssey::image::Image> image;
	image = reader.read(name);

	boost::shared_ptr<Image> asset = boost::make_shared<Image>(name, Type::IMAGE_JPEG, image);

	return asset;
}
