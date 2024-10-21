#include <iostream>
#include <vector>
using namespace std;

// Helper function to calculate the number of valid arrays
int dfs(int n, int m, vector<int>& arr, int prev, vector<vector<int>> &dp) {
    long long M = 1e9 + 7;
    if(n == 0)
        return 1;
    
    if(arr[n-1] != 0) {
        if(abs(arr[n-1]-prev) > 1)
            return 0;

        return dfs(n-1, m, arr, arr[n-1], dp)%M;
    }

    if(dp[n][prev] != -1)
        return dp[n][prev];

    int ways = 0;

    if(prev-1 >= 1 && prev-1 <= m)
        ways = (ways%M + dfs(n-1, m, arr, prev-1, dp)%M)%M;

    if(prev >= 1 && prev <= m)
        ways = (ways%M + dfs(n-1, m, arr, prev, dp)%M)%M;

    if(prev+1 >= 1 && prev+1 <= m)
        ways = (ways%M + dfs(n-1, m, arr, prev+1, dp)%M)%M;

    return dp[n][prev] = ways;
}

int count_arrays(int n, int m, vector<int>& arr) {
    long long M = 1e9 + 7;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    if(arr[n-1] == 0) {
        int ways = 0;

        for(int i=1;i<=m;i++) {
            ways = (ways%M + dfs(n-1, m, arr, i, dp)%M)%M;
        }

        return ways;
    }

    return dfs(n-1, m, arr, arr[n-1], dp);
}

int main() {
    int n, m;
    
    // Reading input for array size and upper bound
    cin >> n >> m;
    
    vector<int> arr(n);  // Array to store the input values
    
    // Reading the array contents
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Calling the helper function to get the count of valid arrays
    int result = count_arrays(n, m, arr);
    
    // Output the result modulo 10^9+7
    cout << result << endl;
    
    return 0;
}
