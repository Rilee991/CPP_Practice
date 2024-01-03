#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "PieceType.hpp"
using namespace std;

class Player {
    string name;
    int moves;
    PieceType type;
    vector<int> rowSum;
    vector<int> colSum;
    vector<int> diagSum;
    vector<int> revDiagSum;

    public:
        Player(string name, PieceType p);
        int getMoves();
        void setMoves(int m);
        string getName();
        PieceType getPieceType();
        void setSumArrays(int boardSize);
        vector<int> getRowSum();
        void setRowSum(int idx, int val);
        vector<int> getColSum();
        void getColSum(vector<int> colSum);
        vector<int> getDiagSum();
        void setDiagSum(vector<int> diagSum);
        vector<int> getRevDiagSum();
        void setRevDiagSum(vector<int> revDiagSum);
};

#endif