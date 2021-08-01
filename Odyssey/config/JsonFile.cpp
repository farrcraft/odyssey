/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
**/

#include"JsonFile.h"

#include <cstdio>
#include <string>

/**
 **/
JsonFile::JsonFile(JsonFile&& other) noexcept
    : _handle(other._handle) {
    other._handle = nullptr;
}

/**
 **/
JsonFile::JsonFile(char const* path, char const* mode) {
    open(path, mode);
}

/**
 **/
JsonFile& JsonFile::operator=(JsonFile&& other) noexcept {
    close();
    _handle = other._handle;
    other._handle = nullptr;
    return *this;
}

/**
 **/
JsonFile::~JsonFile() {

	if (_handle) {
		std::fclose(_handle);
	}
}

/**
 **/
void JsonFile::open(char const* path, char const* mode) {
    boost::json::error_code ec;
    open(path, mode, ec);
    if (ec) {
        throw boost::json::system_error(ec);
    }
}

/**
 **/
long JsonFile::size() const noexcept {
    return _size;
}

/**
 **/
bool JsonFile::eof() const noexcept {
    return std::feof(_handle) != 0;
}

/**
 **/
void JsonFile::close() {
    if (_handle) {
        std::fclose(_handle);
        _handle = nullptr;
        _size = 0;
    }
}

/**
 **/
void JsonFile::fail(boost::json::error_code& ec) {
    ec.assign(errno, boost::json::generic_category());
}

/**
 **/
void JsonFile::open(char const* path, char const* mode, boost::json::error_code& ec) {
    close();
    errno_t err = fopen_s(&_handle, path, mode);
    if (err != 0) {
        return fail(ec);
    }
    if (std::fseek(_handle, 0, SEEK_END) != 0) {
        return fail(ec);
    }
    _size = std::ftell(_handle);
    if (_size == -1) {
        _size = 0;
        return fail(ec);
    }
    if (std::fseek(_handle, 0, SEEK_SET) != 0) {
        return fail(ec);
    }
}

/**
 **/
std::size_t JsonFile::read(char* data, std::size_t size, boost::json::error_code& ec) {
    auto const nread = std::fread(data, 1, size, _handle);
    if (std::ferror(_handle)) {
        ec.assign(errno, boost::json::generic_category());
    }
    return nread;
}

/**
 **/
std::size_t JsonFile::read(char* data, std::size_t size) {
    boost::json::error_code ec;
    auto const nread = read(data, size, ec);
    if (ec) {
        throw boost::json::system_error(ec);
    }
    return nread;
}
