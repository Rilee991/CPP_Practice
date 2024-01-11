#include "Player.hpp"

Player::Player(string n, Symbol s) {
    name = n;
    symbol = s;
}

string Player::getName() {
    return name;
}

int Player::getMoves() {
    return moves;
}

void Player::setMoves(int m) {
    moves = m;
}

Symbol Player::getSymbol() {
    return symbol;
}
