/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Manager.h"
#include "loader/Jpeg.h"
#include "loader/Png.h"

#include <boost/make_shared.hpp>

using namespace odyssey::asset;

/**
 **/
Manager::Manager(const std::string& path) :
	path_(path) {
	loaders_[asset::Type::IMAGE_JPEG] = boost::make_shared<odyssey::asset::loader::Jpeg>();
	loaders_[asset::Type::IMAGE_PNG] = boost::make_shared<odyssey::asset::loader::Png>();
}

/**
 **/
boost::shared_ptr<Loader> Manager::resolveLoader(asset::Type t) {
	auto search = loaders_.find(t);
	if (search == loaders_.end()) {
		throw std::invalid_argument("no loader for type");
	}
	return search->second;
}

/**
 **/
boost::shared_ptr<Asset> Manager::load(const std::string& name, asset::Type t) {
	boost::filesystem::path assetPath = path_;
	assetPath /= name;

	boost::shared_ptr<Loader> loader = resolveLoader(t);
	boost::shared_ptr<Asset> asset = loader->load(assetPath.string());
	return asset;
}

/**
 **/
boost::shared_ptr<Asset> Manager::loadTypeFromExt(const std::string& name) {
	boost::filesystem::path pathName(name);
	boost::shared_ptr<Asset> asset;
	std::string ext = pathName.extension().string();
	if (ext == ".png") {
		asset = load(name, asset::Type::IMAGE_PNG);
	}
	else if (ext == ".jpg") {
		asset = load(name, asset::Type::IMAGE_JPEG);
	}
	else {
		throw std::invalid_argument("unrecognized extension");
	}
	return asset;
}
