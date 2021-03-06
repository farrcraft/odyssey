/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2022 Joshua Farr (josh@farrcraft.com)
 **/


#include "Png.h"

#pragma pack(push, 1)

#include <png.h>

#pragma pack(pop)

#include <iostream>
#include <cstdio>

#include <boost/make_shared.hpp>

using namespace odyssey::image;
using namespace odyssey::image::reader;

/**
 **/
Png::Png() {
}

/**
 **/
Png::~Png() {
}

/**
 **/
boost::shared_ptr<Image> Png::read(std::string_view filename) {
	boost::shared_ptr<Image> empty_ptr;

	// open the file
	FILE * fp;
	errno_t err = fopen_s(&fp, static_cast<std::string>(filename).c_str(), "rb");
	if (err != 0) {
		return empty_ptr;
	}

	// make sure it's really a png file
    png_byte sig[8];
    fread(sig, 1, 8, fp);
    if (!png_check_sig(sig, 8)) {
		return empty_ptr;
    }

	png_structp png_ptr = 0;
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
	if (!png_ptr) {
		return empty_ptr;
    }

	png_infop info_ptr = 0;
	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) {
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return empty_ptr;
	}

	png_init_io(png_ptr, fp);

	png_set_sig_bytes(png_ptr, 8);

	// read all PNG info up to image data
	png_read_info(png_ptr, info_ptr);

	// get width, height, bit-depth and color-type
	png_uint_32 width, height;
	int bpp, colors;
	png_get_IHDR(png_ptr, info_ptr, &width, &height, &bpp, &colors, 0, 0, 0);

	// convert to 3x8 RGB if necessary
	if (bpp == 16)
		png_set_strip_16(png_ptr);
	if (colors == PNG_COLOR_TYPE_PALETTE)
		png_set_expand(png_ptr);
	if (bpp < 8)
		png_set_expand(png_ptr);
	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
		png_set_expand(png_ptr);
	if (colors == PNG_COLOR_TYPE_GRAY || colors == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png_ptr);

	// after the transformations have been registered update info_ptr data
	png_read_update_info(png_ptr, info_ptr);

	// get width, height and the new bit-depth and color-type
	png_get_IHDR(png_ptr, info_ptr, &width, &height, &bpp, &colors, 0, 0, 0);

	// row_bytes is the width x number of channels
	size_t rowbytes;
	unsigned int channels;
	rowbytes = png_get_rowbytes(png_ptr, info_ptr);
	channels = png_get_channels(png_ptr, info_ptr);

	// now we can allocate memory to store the image
	boost::shared_ptr<Image> img = boost::make_shared<Image>(width, height, channels * bpp);
	unsigned char * data = img->data();

	// and allocate memory for an array of row-pointers
	png_byte ** rowpointers = 0;
	rowpointers = new png_bytep[height];

	// set the individual row-pointers to point at the correct offsets
	unsigned int j = (height - 1);
	for (unsigned int i = 0; i < height; i++) {
		rowpointers[j] = data + (i * rowbytes);
		j--;
	}

	// now we can go ahead and just read the whole image
	png_read_image(png_ptr, rowpointers);

	// read the additional chunks in the PNG file (not really needed)
	png_read_end(png_ptr, 0);

	delete [] rowpointers;

	fclose(fp);
	return img;
}
