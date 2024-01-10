#include "Entity.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Snake.hpp"
#include "Ladder.hpp"

int main () {
    int numOfSnakes, numOfLadders, numOfPlayers, numOfDices, boardSize;
    list<Entity*> snakes;
    list<Entity*> ladders;
    list<Player*> players;
    int start, end;
    string name;

    cout<<"Enter num of snakes:";
    cin>>numOfSnakes;

    cout<<"Enter snake coordinates:\n";
    while(numOfSnakes--) {
        cin>>start>>end;
        snakes.push_back(new Snake(start, end));
    }

    cout<<"Enter num of ladders:";
    cin>>numOfLadders;

    cout<<"Enter ladder coordinates:\n";
    while(numOfLadders--) {
        cin>>start>>end;
        ladders.push_back(new Ladder(start, end));
    }

    cout<<"Enter num of players:";
    cin>>numOfPlayers;

    cout<<"Enter players name:\n";
    while(numOfPlayers--) {
        cin>>name;
        players.push_back(new Player(name));
    }

    cout<<"Enter num of dices:";
    cin>>numOfDices;

    cout<<"Enter board Size:";
    cin>>boardSize;

    Dice* dice = new Dice(numOfDices);
    Board* board = new Board(boardSize, players, ladders, snakes, dice);

    board->startGame();
}