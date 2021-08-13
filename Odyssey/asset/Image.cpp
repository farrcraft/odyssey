/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Image.h"

using namespace odyssey::asset;

/**
 **/
Image::Image(const std::string& name, Type t, boost::shared_ptr<odyssey::image::Image> img) : 
	Asset(name, t),
	image_(img) {

}

/**
 **/
boost::shared_ptr<odyssey::image::Image> Image::image() {
	return image_;
}