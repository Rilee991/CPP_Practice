#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(int);
    int res = 0;

    int dp[n-1][n-1];

    for(int gap=0;gap<n;gap++) {
        for(int i=0, j=gap;j<n-1;i++,j++) {
            if(gap == 0) {
                dp[i][j] = 0;
            } else if(gap == 1) {
                dp[i][j] = arr[i]*arr[j]*arr[j+1];
            } else {
                int val = INT_MAX;
                for(int k=i;k<j;k++) {
                    int lc = dp[i][k];
                    int rc = dp[k+1][j];
                    int mc = arr[i]*arr[k+1]*arr[j+1];

                    val = min(val, lc+rc+mc);
                }
                dp[i][j] = val;
            }
        }
    }

    cout<<dp[0][n-2];
}
