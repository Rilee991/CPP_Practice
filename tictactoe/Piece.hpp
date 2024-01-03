#pragma once
#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include "PieceType.hpp"
using namespace std;

class Piece {
    protected:
        PieceType type;
    public:
        Piece(PieceType pType);
};


#endif