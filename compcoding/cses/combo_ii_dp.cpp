#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
#include <set>
using namespace std;


vector<vector<int>> dp;

void takeArrayInput(vector<int> &arr, int n) {
    for(int i=0;i<n;i++)
        cin>>arr[i];
}

// int dfs(int n, int sum, vector<int> &coins) {
//     if(sum == 0)
//         return 1;
//     else if(sum < 0 || n == 0)
//         return 0;
    
//     if(dp[n][sum] != -1)
//         return dp[n][sum];
    
//     long long take = (long long)dfs(n, sum-coins[n-1], coins);
//     long long noTake = (long long)dfs(n-1, sum, coins);

//     return dp[n][sum] = (int)(take%M + noTake%M)%M;
// }

int solve(int n, int sum, vector<int> &coins) {
    // dp.resize(coins.size()+1, vector<int> (sum+1, 0));
    vector<int> curr(sum+1, 0), prev(sum+1, 0);
    long long M = 1e9+7;

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=sum;j++) {
            if(j == 0) {
                curr[j] = 1;
            } else if(i == 0) {
                curr[j] = 0;
            } else if(j >= coins[i-1]) {
                int take = (int)curr[j-coins[i-1]];
                int noTake = (int)prev[j];

                curr[j] = (int)(take%M + noTake%M)%M;
            } else {
                curr[j] = prev[j];
            }
        }

        prev = curr;
    }

    return curr[sum];
}

int main() {
    int n,x;
    cin>>n>>x;

    vector<int> coins(n);

    takeArrayInput(coins, n);

    cout<<solve(n, x, coins);
    return 0;
};