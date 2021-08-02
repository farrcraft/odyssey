/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include <SDL.h>

#include "Odyssey.h"
#include "engine/Engine.h"

/**
 **/
int main(int argc, char* argv[]) {
	Engine engine;
	if (!engine.initialize()) {
		return -1;
	}

	engine.run();

	if (!engine.shutdown()) {
		return -1;
	}

	return 0;
}
