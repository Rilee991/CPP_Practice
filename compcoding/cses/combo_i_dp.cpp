#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long M = 1e9+7;

void takeArrayInput(vector<int> &coins, int n) {
    for(int i=0;i<n;i++)
        cin>>coins[i];
}

int solve(int n, int sum, vector<int> &coins) {
    int dp[sum+1];
    dp[0] = 1;

    for(int s=1;s<=sum;s++) {
        long long ways = 0;

        for(int i=0;i<n;i++) {
            long long res = s-coins[i] >= 0 ? (long long)dp[s-coins[i]] : 0;

            ways = (ways%M + res%M)%M;
        }

        dp[s] = (int)ways;
    }

    return dp[sum];
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);  // see Fast Input & Output
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);

    takeArrayInput(coins, n);

    cout<<solve(n, x, coins);
    return 0;
};