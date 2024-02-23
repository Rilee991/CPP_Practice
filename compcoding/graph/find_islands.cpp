//{ Driver Code Starts
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// } Driver Code Ends

struct Cell {
    int row, col;

    bool operator<(const Cell &c2) const {
        if(row == c2.row)   return col < c2.col;
        return row < c2.row;
    }
};

class Solution {
  public:
    // Function to find the number of islands.
    Cell findParent(Cell node, map<Cell,Cell> &parent) {
        if(parent[node].row == node.row && parent[node].col == node.col)
            return node;
        
        return parent[node] = findParent(parent[node], parent);
    }
    
    vector<Cell> getNeighbors(Cell node, vector<vector<char>>& grid) {
        int dx[8] = {-1,-1,-1,1,1,1,0,0};
        int dy[8] = {-1,0,1,-1,0,1,-1,1};
        vector<Cell> adjCells;
        
        for(int i=0;i<8;i++) {
            int row = node.row + dx[i];
            int col = node.col + dy[i];
            
            if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == '1') {
                adjCells.push_back({row,col});
            }
        }
        
        return adjCells;
    }

    int numIslands(vector<vector<char>>& grid) {
        map<Cell,Cell> parent;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == '1')
                    parent[{i,j}] = {i,j};
            }
        }

        // for(auto it: parent)
        //     cout<<it.first.row<<" "<<it.first.col<<" - "<<it.second.row<<" "<<it.second.col<<"\n";
        
        int numOfIslands = parent.size();

        // 0 1
        // 1 0
        // 1 1
        // 1 0

        // 4 2
        // 0 1
        // 1 0
        // 1 1
        // 1 0
        
        for(auto it: parent) {
            Cell node = it.first;
            Cell ultParentNode = findParent(node, parent);
            cout<<"Cell Node:"<<node.row<<" "<<node.col<<" Ult Parent:"<<ultParentNode.row<<" "<<ultParentNode.col<<"\n";
            vector<Cell> adjCells = getNeighbors(node, grid);

            // cout<<"Adjacent cells\n";
            // for(Cell &cell: adjCells) {
            //     cout<<"Adj Cell Node:"<<cell.row<<" "<<cell.col<<"\n";
            //     cout<<"\n";
            // }
            
            for(Cell adjCell: adjCells) {
                Cell ultParentAdjNode = findParent(adjCell, parent);
                cout<<"Adj Node:"<<adjCell.row<<" "<<adjCell.col<<" Ult Parent:"<<ultParentAdjNode.row<<" "<<ultParentAdjNode.col<<"\n";
            
                if(ultParentNode.row != ultParentAdjNode.row || ultParentNode.col == ultParentAdjNode.col) {
                    cout<<"Parent upadted\n";
                    parent[ultParentAdjNode] = node;
                    numOfIslands--;
                }
            }
        }
        
        return numOfIslands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends