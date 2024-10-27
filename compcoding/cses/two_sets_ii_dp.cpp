#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int MOD = 1000000007;

// Function to compute the result for a given n (to be implemented)
int dfs(int n, int sum) {
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;
    
    int take = dfs(n-1, sum-n)%MOD;
    int noTake = dfs(n-1, sum)%MOD;

    return (take + noTake)%MOD;
}

int computeResult(int n) {
    int sum = (n*(n+1))/2;

    if(sum&1)
        return 0;
    // vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1, 0));
    vector<int> curr(sum/2 + 1, 0);
    vector<int> prev(sum/2 + 1, 0);

    prev[0] = 1;

    for(int i=1;i<=n;i++) {
        for(int s=0;s<=(sum/2);s++) {
            if(s == 0)
                curr[s] = 1;
            else {
                int take = prev[s-i]%MOD;
                int noTake = prev[s]%MOD;

                curr[s] = (take + noTake)%MOD;
            }
        }
        prev = curr;
    }

    return curr[sum/2]/2;
    // return dfs(n, sum/2)/2;
}

int main() {
    int n;

    // Input the integer n
    cin >> n;

    // Calculate the result modulo 10^9+7
    int result = computeResult(n);

    // Output the result
    cout << result << endl;

    return 0;
}
