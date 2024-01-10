#include "Board.hpp"

Board::Board(int boardSize, list<Player*> players, list<Entity*> ladders, list<Entity*> snakes, Dice* dice) {
    this->players = players;
    this->ladders = ladders;
    this->snakes = snakes;
    this->dice = dice;
    this->boardSize = boardSize;
}

void Board::startGame() {
    int winningCell = boardSize * boardSize;
    while(true) {
        for(auto player: players) {
            int currPos = player->getPosition();
            string name = player->getName();
            int sixes = 0, initialPos = currPos;

            while(true) {
                int diceVal = dice->rollDice();
                player->setMoves(player->getMoves()+1);
                currPos = player->getPosition();

                if(diceVal == 6) sixes++;
                if(sixes == 3) {
                    player->setPosition(initialPos);
                    break;
                }

                int newPos = currPos + diceVal;
                bool won = false;

                if(newPos > winningCell) {
                    newPos = currPos;
                } else if(newPos == winningCell) {
                    won = true;
                } else {
                    // Check for ladders
                    bool ladderEncountered = false;
                    for(auto ladder: ladders) {
                        if(ladder->getStart() == newPos) {
                            newPos = ladder->getEnd();
                            ladderEncountered = true;
                            break;
                        }
                    }

                    if(!ladderEncountered) {
                        for(auto snake: snakes) {
                            if(snake->getStart() == newPos) {
                                newPos = snake->getEnd();
                                break;
                            }
                        }
                    }
                }

                player->setPosition(newPos);

                cout<<name<<" rolled a "<<diceVal<<" and moved from "<<currPos<<" to "<<newPos<<"\n";
                if(won) {
                    cout<<name<<" wins the game\n";
                    return;
                }

                if(diceVal != 6) break;
            }
        }
    }
}
