/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include <string_view>
#include <vector>

namespace odyssey::input {

	/**
	 **/
	class KeyState {
	public:
		/**
		 * @return bool
		 **/
		bool pressed(std::string_view c) const;

		/**
		 * @return bool
		 **/
		bool operator() (std::string_view c);

	private:
		std::vector<std::string_view> keys_;
	};

};