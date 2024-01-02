#include <iostream>
#include "GameBoard.hpp"
using namespace std;

int main() {
    int boardSize = 100;
    vector<Player*> players = {new Player("Rohit"), new Player("Mohit")}; 
    Dice* dice = new Dice(6, 3);
    vector<Entity*> entity = {new Entity(10, 15), new Entity(22, 66), new Entity(99, 4), new Entity(45, 71)};
 
    GameBoard* gb = new GameBoard(boardSize, players, dice, entity);

    gb->startGame();
}