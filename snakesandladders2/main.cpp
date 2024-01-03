#include <iostream>
#include "Ladder.hpp"
#include "Snake.hpp"
#include "Game.hpp"

int main() {
    int boardSize = 10;
    Dice* dice = new Dice(6, 1);
    std::vector<Player*> players = { new Player("Razor"), new Player("Ming"), new Player("Jewels") };
    Entity* l1 = new Ladder(10, 43);
    Entity* l2 = new Ladder(34, 79);
    Entity* s1 = new Ladder(95, 22);
    Entity* s2 = new Ladder(78, 4);

    std::vector<Entity*> entities = { l1, l2, s1, s2 };

    Game *game = new Game(boardSize, players, dice, entities);
    game->startGame();
}