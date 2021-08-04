/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Bootstrap.h"
#include "JsonFile.h"

#include <boost/filesystem.hpp>

#include <iostream>

using namespace odyssey::config;

/**
 **/
Bootstrap::Bootstrap() :
    windowWidth_(300),
    windowHeight_(200) {

}

/**
 **/
bool Bootstrap::load(odyssey::engine::Logger &logger) {
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

        dataPath_ = boost::json::value_to<std::string>(object.at("data_path"));
        LOG_INFO(logger) << "Found data path: " << dataPath_;

        auto const window = object.at("window");
        windowWidth_ = boost::json::value_to<int>(window.at("width"));
        windowHeight_ = boost::json::value_to<int>(window.at("height"));
        LOG_INFO(logger) << "Setting default window size to " << windowWidth_ << "x" << windowHeight_;
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
    return windowWidth_;
}

/**
 **/
int Bootstrap::windowHeight() const {
    return windowHeight_;
}
