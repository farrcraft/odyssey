/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include <string>

namespace odyssey::event {

	/**
	 **/
	class Key {
	public:
		/**
		 **/
		Key(const std::string_view &name, bool pressed);

		/**
		 **/
		bool pressed() const;

		/**
		 **/
		std::string_view name() const;
	private:
		std::string name_;
		bool pressed_;
	};
};
