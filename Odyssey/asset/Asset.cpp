/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Asset.h"

using namespace odyssey::asset;

Asset::Asset(const std::string& name, asset::Type t) :
	name_(name),
	type_(t) {

}
