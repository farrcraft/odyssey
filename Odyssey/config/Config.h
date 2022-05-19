/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include "BindingContext.h"
#include "../asset/Manager.h"

#include <boost/shared_ptr.hpp>

#include <unordered_map>
#include <string_view>

namespace odyssey::config {
	/**
	 **/
	class Config final {
	public:
		/**
		 **/
		Config(const boost::shared_ptr<odyssey::engine::Logger> &logger);

		/**
		 **/
		bool load(const boost::shared_ptr<odyssey::asset::Manager>& assetManager);
		
	protected:
		/**
		 **/
		bool loadBindings(const boost::shared_ptr<odyssey::asset::Json>& bindings);

	private:
		std::unordered_map<std::string_view, boost::shared_ptr<BindingContext> > contexts_;
		boost::shared_ptr<odyssey::engine::Logger> logger_;
	};
};
