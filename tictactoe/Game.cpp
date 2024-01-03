#include "Game.hpp"
using namespace std;

Game::Game(int bSize, vector<Player*> p): board(bSize) {
    players = p;
    
    for(Player* pl : p) { 
        pl->setSumArrays(bSize);
    }
}

void Game::startGame() {
    for(auto player: players) {
        int row, col;
        cout<<"Player "<<player->getName()<<"'s turn: Please enter row and col\n";
        cin>>row>>col;

        bool assignRes = board.assignPiece(player->getPieceType(),row,col);

        if(!assignRes) {
            cout<<"Invalid cell selected. Please try again\n";
            continue;
        }


        if(board.checkResult(player)) {
            cout<<"Winner: "<<player->getName()<<" Moves:"<<player->getMoves()<<"\n";
            return;
        }
    }
}
