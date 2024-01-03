#include <iostream>
#include "Board.hpp"
#include <vector>
using namespace std;

Board::Board(int bSize) {
    boardSize = bSize;
    board.resize(bSize, vector<PieceType>(bSize, PieceType::E));
}

bool Board::assignPiece(PieceType p, int row, int col) {
    if(row > boardSize || row < 1 || col > boardSize || col < 1) return false;

    board[row-1][col-1] = p;
}

void Board::displayBoard() {
    for(int i=0;i<boardSize;i++) {
        for(int j=0;j<boardSize;j++) {
            cout<<getEnumValue(board[i][j])<<" | ";
        }
        cout<<"\n";
    }
}


char Board::getEnumValue(PieceType type) {
    switch(type) {
        case PieceType::E: return 'E';
        case PieceType::O: return 'O';
        case PieceType::X: return 'X';
        default: return 'X';
    }
}

bool Board::checkResult(Player *player) {
    const PieceType type = player->getPieceType();

    for(int i=0;i<boardSize;i++) {
        
    }
}