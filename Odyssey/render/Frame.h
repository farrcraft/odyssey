/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "Operation.h"

#include <vector>

#include <boost/shared_ptr.hpp>

namespace odyssey::render {
	/**
	 **/
	class Frame {
	public:
		/**
		 **/
		void addOperation(boost::shared_ptr<Operation> operation);

	private:
		std::vector<boost::shared_ptr<Operation>> operations_;
	};
};
