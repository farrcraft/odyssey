/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Engine.h"
#include "../ui/Window.h"

// probably just temporary here for initial image loading/display test
#include "../image/Image.h"
#include "../image/reader/Png.h"
#include <boost/filesystem.hpp>

#include <SDL.h>

using namespace odyssey::engine;

/**
 **/
bool Engine::initialize() {
	logger_.initialize();
	LOG_INFO(logger_) << "Initializing engine...";

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		LOG_ERROR(logger_) << "SDL could not initialize! SDL_Error: " << SDL_GetError();
		return false;
	}

	if (!bootstrap_.load(logger_)) {
		return false;
	}

	return true;
}

/**
 **/
bool Engine::shutdown() {
	LOG_INFO(logger_) << "Shutting down engine...";

	// Quit SDL subsystems
	SDL_Quit();
	return true;
}

/**
 **/
bool Engine::run() {
	odyssey::ui::Window window(logger_);
	if (!window.create(bootstrap_.windowWidth(), bootstrap_.windowHeight())) {
		return false;
	}

	bool quit = false;
	SDL_Event e;

	// let's just hardcode an image to load from our data path
	boost::filesystem::path imagePath(bootstrap_.dataPath());
	imagePath /= "sample.png";
	odyssey::image::reader::Png reader;
	boost::shared_ptr<odyssey::image::Image> image;
	image = reader.read(imagePath.string());

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
	SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(image->data(), image->width(), image->height(), image->bpp(), ((image->bpp() / 8) * image->width()), rmask, gmask, bmask, amask);
	if (surface == NULL) {
		LOG_ERROR(logger_) << "Error creating surface from image: " << SDL_GetError();
		return false;
	}

	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}

		// and draw the image on the screen
		window.paint(surface);

		/*
		//Apply the image
		SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);

		//Wait two seconds
		SDL_Delay(2000);
		*/
	}

	SDL_FreeSurface(surface);

	window.destroy();
	return true;
}

/**
 **/
Logger& Engine::logger() {
	return logger_;
}
