/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Bootstrap.h"
#include "JsonFile.h"

#include <iostream>

/**
 **/
bool Bootstrap::load() {
    try {
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
    }
    catch (std::exception const& e) {
        std::cerr <<
            "Caught exception: "
            << e.what() << std::endl;
        return false;
    }

	return true;
}
