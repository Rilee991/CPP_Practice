#include "Board.hpp"

Board::Board(list<Player*> players, int bSize) {
    this->players = players;
    boardSize = bSize;
    grid.resize(bSize, vector<Symbol> (bSize, Symbol::SYM_EMPTY));
}

void Board::startGame() {
    bool isGameOver = false;
    int r, c, turns = 0;
    cout<<"Game starting...\n";
    printBoard();
    while(!isGameOver) {
        for(auto player: players) {
            makeMove(player,r,c);
            printBoard();
            if(checkWinner(player,r,c)) {
                cout<<"Winner:"<<player->getName()<<"\n";
                isGameOver = true;
                break;
            }
            turns++;
            if(turns == boardSize*boardSize) {
                cout<<"Match draw\n";
                isGameOver = true;
                break;
            }
        }
    }
    cout<<"Game Over\n";
    return;
}

bool Board::checkWinner(Player* player, int r, int c) {
    // For row
    int rowSum = 0, colSum = 0, diagSum = 0, revDiagSum = 0;
    for(int i=0;i<boardSize;i++) rowSum += grid[r][i] == player->getSymbol();
    for(int i=0;i<boardSize;i++) colSum += grid[i][c] == player->getSymbol();
    if(r+c+1 == boardSize) {
        for(int i=0;i<boardSize;i++) diagSum += grid[i][i] == player->getSymbol();
        for(int i=0;i<boardSize;i++) revDiagSum += grid[i][boardSize-i-1] == player->getSymbol();
    }

    if(rowSum == boardSize || colSum == boardSize || diagSum == boardSize || revDiagSum == boardSize)   return true;
    return false;
}

char getEnumValue (Symbol sym) {
    return static_cast<char>(sym);
}

void Board::makeMove(Player* player, int& r, int& c) {
    bool isValid = false;
    while(!isValid) {
        cout<<player->getName()<<" select cell to make "<<getEnumValue(player->getSymbol())<<"\n";
        cin>>r>>c;
        r--;
        c--;
        player->setMoves(player->getMoves()+1);
        if(!isValidMove(r,c)) {
            cout<<"Invalid move! Try again.";
            continue;
        }
        isValid = true;
    }

    grid[r][c] = player->getSymbol();
}

bool Board::isValidMove(int r, int c) {
    if(r < 0 || r >= boardSize || c < 0 || c >= boardSize || grid[r][c] != Symbol::SYM_EMPTY)    return false;
    return true;
}

void Board::printBoard() {
    cout<<"Board status:\n";
    for(int i=0;i<boardSize;i++) {
        for(int j=0;j<boardSize;j++) {
            cout<<getEnumValue(grid[i][j]);
            // cout<<((i == boardSize-1) ? "" : " _ ");
            cout<<((j == boardSize-1) ? "" : " | ");
        }
        cout<<"\n";
    }
}
