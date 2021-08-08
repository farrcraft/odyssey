/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Asset.h"

using namespace odyssey::asset;

Asset::Asset(odyssey::engine::Logger& logger, const std::string& name, asset::type::Type t) :
	logger_(logger),
	name_(name),
	type_(t) {

}
