/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "ImageSurface.h"

#include "../image/reader/Png.h"

using namespace odyssey::asset;

/**
 **/
ImageSurface::ImageSurface(odyssey::engine::Logger& logger, const std::string& name, Type t) :
	Asset(logger, name, t),
	surface_(nullptr) {

}

/**
 **/
ImageSurface::~ImageSurface() {
	if (surface_ != NULL) {
		SDL_FreeSurface(surface_);
	}
}

/**
 **/
bool ImageSurface::load(const std::string &path) {
	odyssey::image::reader::Png reader;
	boost::shared_ptr<odyssey::image::Image> image;
	image = reader.read(path);

	Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	int shift = (image->bpp() == 24) ? 8 : 0;
	rmask = 0xff000000 >> shift;
	gmask = 0x00ff0000 >> shift;
	bmask = 0x0000ff00 >> shift;
	amask = 0x000000ff >> shift;
#else // little endian, like x86
	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = (image->bpp() == 24) ? 0 : 0xff000000;
#endif
	surface_ = SDL_CreateRGBSurfaceFrom(image->data(), image->width(), image->height(), image->bpp(), ((image->bpp() / 8) * image->width()), rmask, gmask, bmask, amask);
	if (surface_ == NULL) {
		LOG_ERROR(logger_) << "Error creating surface from image: " << SDL_GetError();
		return false;
	}
	return true;
}
