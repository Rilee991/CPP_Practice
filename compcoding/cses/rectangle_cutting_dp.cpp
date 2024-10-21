#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to calculate the minimum number of moves (to be implemented)
int minMoves(int len, int wid) {
    vector<vector<int>> dp(len+1, vector<int> (wid+1, 0));

    for(int i=1;i<=len;i++) {
        for(int j=1;j<=wid;j++) {
            if(i == 1) {
                dp[i][j] = j-1;
            } else if(i == j) {
                dp[i][j] = 0;
            } else {
                int res = INT_MAX;

                int start = 1, end = i-1;
                while(start <= end) {
                    res = min(res, 1 + dp[start][j] + dp[end][j]);
                    start++;
                    end--;
                }

                start = 1, end = j-1;
                while(start <= end) {
                    res = min(res, 1 + dp[i][start] + dp[i][end]);
                    start++;
                    end--;
                }

                dp[i][j] = res;
            }

            if(j <= len && i <= wid)
                dp[j][i] = dp[i][j];
        }
    }

    return dp[len][wid];
}

int main() {
    int a, b;
    
    // Input the two integers a and b
    cin >> a >> b;

    // Call the function to compute the minimum number of moves
    int result = minMoves(a, b);

    // Output the result
    cout << result << endl;

    return 0;
}
