#include <iostream>
#include "Board.hpp"
using namespace std;

int main() {
    unordered_map<char,Symbol> charSymMapping;
    charSymMapping['X'] = Symbol::SYM_X;
    charSymMapping['Y'] = Symbol::SYM_Y;
    charSymMapping['Z'] = Symbol::SYM_Z;
    charSymMapping['O'] = Symbol::SYM_O;

    int numOfPlayers, boardSize;
    string name;
    char sym;
    cin>>numOfPlayers;

    list<Player*> players;
    for(int i=0;i<numOfPlayers;i++) {
        cin>>sym>>name;
        players.push_back(new Player(name,charSymMapping[sym]));
    }

    cin>>boardSize;
    Board* board = new Board(players,boardSize);
    board->startGame();
}