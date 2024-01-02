#include <iostream>
#include "Player.hpp"
using namespace std;

Player::Player(string n) {
    name = n;
    numOfMoves = 0;
    position = 0;
}

int Player::getNumOfMoves() {
	return this->numOfMoves;
}
void Player::setNumOfMoves(int numOfMoves) {
	this->numOfMoves = numOfMoves;
}
string Player::getName() {
	return this->name;
}
void Player::setName(string name) {
	this->name = name;
}
int Player::getPosition() {
	return this->position;
}
void Player::setPosition(int position) {
	this->position = position;
}