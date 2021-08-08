/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Manager.h"
#include "ImageSurface.h"

#include <boost/make_shared.hpp>

using namespace odyssey::asset;

/**
 **/
Manager::Manager(odyssey::engine::Logger& logger, const std::string& path) :
	logger_(logger),
	path_(path) {

}

/**
 **/
bool Manager::load(const std::string& name, asset::type::Type t) {
	boost::filesystem::path assetPath = path_;
	assetPath /= name;
	if (t == odyssey::asset::type::IMAGE_PNG) {
		boost::shared_ptr<ImageSurface> img = boost::make_shared<ImageSurface>(logger_, name, t);
		if (!img->load(assetPath.string())) {
			return false;
		}
		assets_.push_back(img);
	}
	return true;
}
