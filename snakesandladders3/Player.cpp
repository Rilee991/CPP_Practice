#include "Player.hpp"

Player::Player(string name) {
    this->name = name;
    moves = 0;
    position = 0;
}

int Player::getMoves() {
    return moves;
}

int Player::getPosition() {
    return position;
}

void Player::setMoves(int m) {
    this->moves = m;
}

void Player::setPosition(int p) {
    this->position = p;
}

string Player::getName() {
    return name;
}

queue<int> Player::getLastThreeDices() {
    return lastThreeDices;
}

void Player::setLastThreeDices(queue<int> q) {
    lastThreeDices = q;
}


