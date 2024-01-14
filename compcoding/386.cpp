#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

int solve(int arr[], int i, int j, vector<vector<int>> &dp) {
    if(i >= j)  return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    int res = INT_MAX;
    for(int k=i;k<j;k++) {
        int temp = solve(arr,i,k,dp)+ solve(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        res = min(temp, res);
    }

    return dp[i][j] = res;
}

int solveTab(int arr[], int n) {
    vector<vector<int>> dp(n, vector<int>(n,0));

    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<=n-1;j++) {
            if(i >= j) dp[i][j] = 0;
            int res = INT_MAX;
            for(int k=i;k>j;k--) {
                int temp = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                res = min(res, temp);
            }
            dp[i][j] = res;
        }
    }

    return dp[1][n-1];
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(int);
    int res = 0;
    
    vector<vector<int>> dp(n, vector<int>(n,-1));
    // cout<<solve(arr, 1, n-1, dp);
    cout<<solveTab(arr, n);

    // int dp[n-1][n-1];

    // for(int gap=0;gap<n;gap++) {
    //     for(int i=0, j=gap;j<n-1;i++,j++) {
    //         if(gap == 0) {
    //             dp[i][j] = 0;
    //         } else if(gap == 1) {
    //             dp[i][j] = arr[i]*arr[j]*arr[j+1];
    //         } else {
    //             int val = INT_MAX;
    //             for(int k=i;k<j;k++) {
    //                 int lc = dp[i][k];
    //                 int rc = dp[k+1][j];
    //                 int mc = arr[i]*arr[k+1]*arr[j+1];

    //                 val = min(val, lc+rc+mc);
    //             }
    //             dp[i][j] = val;
    //         }
    //     }
    // }

    // cout<<dp[0][n-2];
}
