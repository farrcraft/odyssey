/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Frame.h"

using namespace odyssey::render;

void Frame::addOperation(boost::shared_ptr<Operation> operation) {
	operations_.push_back(operation);
}