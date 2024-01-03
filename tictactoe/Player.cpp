#include <iostream>
#include "Player.hpp"
using namespace std;

Player::Player(string name, PieceType p) {
    this->name = name;
    this->type = p;
}

void Player::setSumArrays(int bSize) {
    rowSum.resize(bSize, 0);
    colSum.resize(bSize, 0);
    diagSum.resize(bSize, 0);
    revDiagSum.resize(bSize, 0);
}

int Player::getMoves() {
    return moves;
}

void Player::setMoves(int m) {
    moves = m;
}

string Player::getName() {
    return name;
}

PieceType Player::getPieceType() {
    return type;
}

vector<int> Player::getRowSum() {
	return rowSum;
}

void Player::setRowSum(int idx, int val) {
	this->rowSum[idx] = val;
}
