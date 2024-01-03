#include <iostream>
#include <vector>
#include "Game.hpp"

Game::Game(int bSize, std::vector<Player*> players, Dice* dice, std::vector<Entity*> entities) {
    board = new Board(bSize, dice, entities);
    this->players = players;
}

void Game::startGame() {
    int winningCell = bSize * bSize;
    while(true) {
        for(auto player: players) {
            int diceVal = dice->rollDice();
            int newPos = player->getPosition() + diceVal;
            bool isEntityCell = false;
            player->setNumOfMoves(player->getNumOfMoves() + 1);

            if(newPos > winningCell) continue;
            if(newPos == winningCell) {
                std::cout<<"Player "<<player->getName()<<" won the game in "<<player->getNumOfMoves()<<" moves.\n";
                return;
            }

            for(auto entity: entities) {
                if(entity->getStart() == newPos) {
                    isEntityCell = true;
                    player->setPosition(newPos);
                    break;
                }
            }

            if(!isEntityCell) {
                player->setPosition(newPos);
            }
        }
    }
}
