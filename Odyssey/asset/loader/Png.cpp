/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Png.h"
#include "../Image.h"
#include "../Type.h"
#include "../../image/reader/Png.h"

#include <boost/make_shared.hpp>

using namespace odyssey::asset;
using namespace odyssey::asset::loader;

/**
 **/
Png::Png() : Loader(Type::IMAGE_PNG) {

}

/**
 **/
boost::shared_ptr<Asset> Png::load(const std::string& name) {
	odyssey::image::reader::Png reader;
	boost::shared_ptr<odyssey::image::Image> image;
	image = reader.read(name);

	boost::shared_ptr<Image> asset = boost::make_shared<Image>(name, Type::IMAGE_PNG, image);

	return asset;
}
