/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Bootstrap.h"
#include "JsonFile.h"

#include <boost/filesystem.hpp>

#include <iostream>

/**
 **/
Bootstrap::Bootstrap() :
    _windowWidth(300),
    _windowHeight(200) {

}

/**
 **/
bool Bootstrap::load(Logger &logger) {
    try {
        boost::filesystem::path path = boost::filesystem::current_path();
        LOG_INFO(logger) << "Current path is: " << path;
        JsonFile file("bootstrap.json", "r");
        boost::json::stream_parser parser;
        boost::json::error_code err;
        do
        {
            char buf[4096];
            auto const nread = file.read(buf, sizeof(buf));
            parser.write(buf, nread, err);
        } while (!file.eof());
        if (err) {
            return false;
        }
        parser.finish(err);
        if (err) {
            return false;
        }
        auto const document = parser.release();
        boost::json::object const& object = document.as_object();

        _dataPath = boost::json::value_to<std::string>(object.at("data_path"));
        LOG_INFO(logger) << "Found data path: " << _dataPath;

        auto const window = object.at("window");
        _windowWidth = boost::json::value_to<int>(window.at("width"));
        _windowHeight = boost::json::value_to<int>(window.at("height"));
        LOG_INFO(logger) << "Setting default window size to " << _windowWidth << "x" << _windowHeight;
    }
    catch (std::exception const& e) {
        LOG_ERROR(logger) << "Bootstrap caught exception: " << e.what();
        return false;
    }

	return true;
}

/**
 **/
int Bootstrap::windowWidth() const {
    return _windowWidth;
}

/**
 **/
int Bootstrap::windowHeight() const {
    return _windowHeight;
}
