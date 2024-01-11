#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "Player.hpp"
#include <list>
#include <unordered_map>
#include <vector>

class Board {
    list<Player*> players;
    int boardSize;
    vector<vector<Symbol>> grid;

    void makeMove(Player* player, int&, int&);
    bool isValidMove(int,int);
    bool checkWinner(Player*, int, int);
    public:
        Board(list<Player*>, int);
        void startGame();
        void printBoard();
};

#endif