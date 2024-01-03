#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "PieceType.hpp"
#include "Player.hpp"
#include <vector>
using namespace std;

class Board {
    vector<vector<PieceType>> board;
    int boardSize;
    public:
        Board(int bSize);
        bool assignPiece(PieceType pType, int row, int col);
        void displayBoard();
        bool checkResult(Player *p);
        char getEnumValue(PieceType type);
};


#endif