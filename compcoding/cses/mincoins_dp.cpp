#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long M = 1e9+7;
vector<int> dp;

void takeArrayInput(vector<int> &coins, int n) {
    for(int i=0;i<n;i++)
        cin>>coins[i];
}

int dfs(int n, int x, vector<int> &coins) {
    if(x == 0)
        return 0;
    if(x < 0)
        return INT_MAX;

    if(dp[x] != -1)
        return dp[x];
    
    int res = INT_MAX;

    for(int i=0;i<n;i++) {
        int take = dfs(n, x-coins[i], coins);

        if(take != INT_MAX)
            take += 1;
        
        res = min(res, take);
    }

    return dp[x] = res;
}

int solve(int n, int x, vector<int> &coins) {
    dp.resize(x+1, -1);
    int res = dfs(n, x, coins);

    return res == INT_MAX ? -1 : res;
}

int main() {
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);

    takeArrayInput(coins, n);
    // cout<<"Arr:\n";
    // for(int coin: coins)
    //     cout<<coin<<" ";
    // cout<<"\nDone\n";

    cout<<solve(n, x, coins);
    return 0;
};