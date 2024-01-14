#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

ll min(ll a, ll b) {
    return a < b ? b : a;
}

ll solve(ll n, ll r, vector<vector<int>> &dp) {
    if(n < r)   return 0;
    else if(r == 0) return 1;
    else if(r == 1) return n;

    if(dp[n][r] != -1)  return dp[n][r];

    return dp[n][r] = solve(n-1,r, dp) + r*solve(n-1,r-1, dp);
}

ll solveTab(ll n, ll r) {
    // vector<vector<int>> dp(n+1, vector<int>(r+1,0));
    vector<int> curr(r+1, 0);
    vector<int> prev(r+1, 0);

    for(ll i=0;i<=n;i++) {
        for(ll j=0;j<=i;j++) {
            if(j == 0)  curr[j] = 1;
            else if(j == 1) curr[j] = i;
            else curr[j] = prev[j]+j*prev[j-1];
        }
        prev = curr;
    }

    return curr[r];
}

int main() {
    ll n = 10, r = 2;
    // vector<vector<int>> dp(n+1, vector<int>(r+1,-1));
    // cout<<solve(n,r, dp);
    cout<<solveTab(n, r);
}
