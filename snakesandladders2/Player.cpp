#include <iostream>
#include "Player.hpp"

Player::Player(std::string name) {
    this->name = name;
    this->numOfMoves = 0;
    this->position = 0;
}

int Player::getNumOfMoves() {
    return numOfMoves;
}

void Player::setNumOfMoves(int moves) {
    this->numOfMoves = moves;
}

int Player::getPosition() {
    return position;
}

std::string Player::getName() {
    return name;
}

void Player::setPosition(int position) {
    this->position = position;
}
