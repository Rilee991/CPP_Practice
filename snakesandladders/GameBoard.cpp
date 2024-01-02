#include "GameBoard.hpp"
#include <iostream>
using namespace std;

GameBoard::GameBoard(int s, vector<Player*> p, Dice* d, vector<Entity*> e) {
    size = s;
    players = p;
    dice = d;
    entities = e;
}

void GameBoard::startGame() {
    bool gameOver = false;

    while(true) {
        for(auto player: players) {
            cout<<"Player "<<player->getName()<<"'s turn---\n";
            int diceVal = dice->rollDice();
            int newPos = player->getPosition() + diceVal;
            bool isEntity = false;
            player->setNumOfMoves(player->getNumOfMoves()+1);
            cout<<"Old position:"<<player->getPosition()<<"\n";
            cout<<"Rolled dice value:"<<diceVal<<"\n";

            if(newPos > size) {
                continue;
            } else if(newPos == size) {
                cout<<"Player:"<<player->getName()<<" has won the game in "<<player->getNumOfMoves()<<" moves.\n";
                return;
            }

            for(auto entity: entities) {
                if(entity->getStart() == newPos) {
                    isEntity = true;
                    player->setPosition(entity->getEnd());
                }
            }

            if(!isEntity) {
                player->setPosition(newPos);
            }
            cout<<"New position:"<<player->getPosition()<<"\n";
        }
    }
}
