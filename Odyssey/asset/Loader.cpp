/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Loader.h"

using namespace odyssey::asset;

/**
 **/
Loader::Loader(Type t) :
	type_(t) {

}

/**
 **/
Type Loader::type() const {
	return type_;
}
