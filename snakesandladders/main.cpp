#include <iostream>
#include <vector>
using namespace std;

class Player {
    int id;
    string name;
    int numOfMoves;
    int position;

    public:
    Player(int id, string name, int numOfMoves, int pos) {
        this->id = id;
        this->name = name;
        this->numOfMoves = numOfMoves;
        this->position = pos;
    }

    int rollDice() {
        int num = (rand()%6) + 1;
        return num;
    }

    void move(int spaces) {
        this->position += spaces;
        this->numOfMoves++;
    }

    int getPosition() {
        return position;
    }
    
    void setPosition(int pos) {
        this->position = pos;
    }

    string getName() {
        return name;
    }
};

class Board {
    public:
    int size;
    vector<int> playerPostions;
    vector<int> ladderPostions;
    vector<int> snakePostions;
    
    Board(int s) {
        this->size = s;
    }

    void movePlayer(Player &player, int spaces) {
        int newPos = player.getPosition() + spaces;

        if(newPos > this->size) {
            cout<<"Invalid Move!! Your position is "<<player.getPosition()<<". Rolled dice is:"<<spaces<<". Exceeded board\n";
            return;
        }

        for(int i=0;i<snakePostions.size();i+=2) {
            if(newPos == snakePostions[i]) {
                newPos = snakePostions[i+1];
                break;
            }
        }

        for(int i=0;i<ladderPostions.size();i+=2) {
            if(newPos == ladderPostions[i]) {
                newPos = ladderPostions[i+1];
                break;
            }
        }

        player.move(newPos);
    }

    bool checkWinner(Player player) {
        if(player.getPosition() == size) {
            cout<<"Player: "<<player.getName()<<" wins.\n";
            return true;
        }
        return false;
    }
};

class Game {
    Board board;
    vector<Player> players;
    vector<pair<int,int> > snakes;
    vector<pair<int,int> > ladders;
    public:

        Game(int bSize, vector<pair<int, string> > p, vector<pair<int,int> > s, vector<pair<int,int> > l): board(bSize) {
            for(int i=0;i<p.size();i++) {
                players.push_back(Player(p[i].first, p[i].second, 0, 1));
            }

            snakes = s;
            ladders = l;

            initialiseBoard();
        }

        void initialiseBoard() {
            for(int i=0;i<snakes.size();i++) {
                board.snakePostions.push_back(snakes[i].first);
                board.snakePostions.push_back(snakes[i].second);
            }

            for(int i=0;i<ladders.size();i++) {
                board.ladderPostions.push_back(ladders[i].first);
                board.ladderPostions.push_back(ladders[i].second);
            }
        }

        void play() {
            while(true) {
                for(int i=0;i<players.size();i++) {
                    int spaces = players[i].rollDice();
                    const string pName = players[i].getName();
                    cout<<pName<<"'s turn\n";
                    cout<<"Initial Position: "<<players[i].getPosition()<< ". Rolled: "<<spaces<<"\n";
                    board.movePlayer(players[i], spaces);
                    cout<<"New position:"<<players[i].getPosition()<<"\n";

                    if(board.checkWinner(players[i])) {
                        return;
                    }
                }
            }
        }
};

int main() {
    vector<pair<int,string> > players;
    vector<pair<int,int> > snakes, ladders;
    players.push_back(make_pair(1, "Razor"));
    players.push_back(make_pair(2, "Ming"));
    snakes.push_back(make_pair(17,7));
    snakes.push_back(make_pair(91,4));
    snakes.push_back(make_pair(65,15));
    ladders.push_back(make_pair(11,76));
    ladders.push_back(make_pair(4,9));
    ladders.push_back(make_pair(35,90));

    Game game(100, players, snakes, ladders);

    game.play();
}