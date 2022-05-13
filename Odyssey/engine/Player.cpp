/**
 * The Untitled Adventure / Odyssey
 * Copyright (c) 2021 Joshua Farr (josh@farrcraft.com)
 **/

#include "Player.h"

using namespace odyssey::engine;

/**
 **/
Player::Player() : position_(0, 0) {

}

/**
 **/
bool Player::tick() {
	return true;
}

/**
 **/
void Player::move(int x, int y) {
	position_.x += x;
	position_.y += y;
}

/**
 **/
glm::ivec2 Player::position() const {
	return position_;
}
