#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

// Function to calculate distinct sums (to be implemented)
vector<int> calculateDistinctSums(vector<int> &coins) {
    int n = coins.size();
    int sum = accumulate(coins.begin(), coins.end(), 0);
    // vector<vector<bool>> dp(n+1, vector<bool> (sum+1, 0));
    vector<bool> curr(sum+1, 0);
    vector<bool> prev(sum+1, 0);
    vector<int> res;

    sort(coins.begin(), coins.end());
    prev[0] = 1;

    for(int i=1;i<=n;i++) {
        for(int total=0;total<=sum;total++) {
            if(total == 0 || prev[total]) {
                curr[total] = 1;
            } else if(total >= coins[i-1]) {
                curr[total] = prev[total-coins[i-1]];
            }
        }
        prev = curr;
    }

    for(int i=1;i<=sum;i++)
        if(curr[i])
            res.push_back(i);

    return res;
}

int main() {
    int n;
    
    // Input number of coins
    cin >> n;

    vector<int> coins(n);
    
    // Input coin values
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    // Calculate distinct sums
    vector<int> distinctSums = calculateDistinctSums(coins);

    // Output the number of distinct sums
    cout << distinctSums.size() << endl;

    // Output each sum in increasing order
    for (int sum : distinctSums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
