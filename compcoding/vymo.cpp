#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void minCost (vector<vector<int>> citiesCost, int n, int h, int aCount, int bCount, string path, int cost, string &respath, int &ans) {
    if(n == 0) {
        reverse(path.begin(),path.end());
        if(ans > cost) {
            ans = cost;
            respath = path;
        }
        cout<<path<<" "<<cost<<"\n";
        return;
    }

    if(aCount < h)
        minCost(citiesCost, n-1, h, aCount+1, bCount, path+"A", cost + citiesCost[n-1][0], respath, ans);
    if(bCount < h)
        minCost(citiesCost, n-1, h, aCount, bCount+1, path+"B", cost + citiesCost[n-1][1], respath, ans);
}

int solve(vector<vector<int>> citiesCost, int n, int h, int aCount, int bCount, vector<vector<vector<int>>> &dp) {
    if(n == 0)  return 0;
    if(aCount == h) return dp[n][aCount][bCount] = citiesCost[n-1][1] + solve(citiesCost, n-1, h, aCount, bCount + 1, dp);
    if(bCount == h) return dp[n][aCount][bCount] = citiesCost[n-1][0] + solve(citiesCost, n-1, h, aCount + 1, bCount, dp);

    int costA = citiesCost[n-1][0] + solve(citiesCost, n-1, h, aCount+1, bCount, dp);
    int costB = citiesCost[n-1][1] + solve(citiesCost, n-1, h, aCount, bCount+1, dp);

    return dp[n][aCount][bCount] = min(costA, costB);
}

int solveTab(vector<vector<int>> citiesCost, int n) {
    int h = n/2;

    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (h+1, vector<int> (h+1, 0)));
    vector<vector<int>> curr(h+1, vector<int> (h+1, 0));
    vector<vector<int>> prev(h+1, vector<int> (h+1, 0));

    for(int i=1;i<=n;i++) {
        for(int ac=0;ac<=h;ac++) {
            for(int bc=0;bc<=h;bc++) {
                if(ac == h) curr[ac][bc] = citiesCost[i-1][1] + prev[ac][bc+1];
                else if(bc == h) curr[ac][bc] = citiesCost[i-1][0] + prev[ac+1][bc];
                else {
                    int costA = citiesCost[i - 1][0] + prev[ac + 1][bc];
                    int costB = citiesCost[i - 1][1] + prev[ac][bc + 1];
                    curr[ac][bc] = min(costA, costB);
                }
            }
        }
        prev = curr;
    }

    return curr[0][0];
}

int main() {
    vector<vector<int>> citiesCost = {{100, 20}, {1, 200}, {4, 5}, {90, 30}};
    string path = "";
    int ans = INT_MAX;
    int n = citiesCost.size();
    int h = n/2;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (h+1, vector<int> (h+1, -1)));
    cout<<solve(citiesCost, n, h, 0, 0, dp);
    // minCost(citiesCost, citiesCost.size(), citiesCost.size()/2, 0, 0, "", 0, path, ans);
    // cout<<"Result\n"<<path<<" "<<ans<<"\n";
    return 0;
}