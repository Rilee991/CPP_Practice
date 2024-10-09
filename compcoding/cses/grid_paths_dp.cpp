#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

void takeArrayInput(vector<int> &coins, int n) {
    for(int i=0;i<n;i++)
        cin>>coins[i];
}

int dfs(vector<vector<char>> &grid, int i, int j, int n, vector<vector<int>> &dp) {
    if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '*')
        return 0;
    if(i == n-1 && j == n-1)
        return 1;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    long long M = 1e9+7;
    
    int right = dfs(grid, i, j+1, n, dp)%M;
    int down = dfs(grid, i+1, j, n, dp)%M;

    return dp[i][j] = (right + down)%M;
}

int solve(vector<vector<char>> &grid, int n) {
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return dfs(grid, 0, 0, n, dp);
}

int main() {
    int n;
    cin>>n;

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    }

    cout<<solve(grid, n);
    return 0;
};