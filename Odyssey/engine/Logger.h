/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#pragma once

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>

/**
 **/
class Logger {
public:
	/**
	 **/
	void initialize();

	/**
	 **/
	boost::log::sources::severity_logger< boost::log::trivial::severity_level > &get();

private:
	boost::log::sources::severity_logger< boost::log::trivial::severity_level > _logger;
};