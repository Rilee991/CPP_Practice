// C++ program of above approach
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// A utility function to get max
// of two integers
int max(int x, int y) { return (x > y) ? x : y; }

// Returns the length of the longest
// palindromic subsequence in seq
int lps(string seq, int i, int j) {
    string rev = seq;
    reverse(rev.begin(),rev.end());
    int n = j+1;

    int dp[n+1][n+1];

    for(int a=0;a<=n;a++) {
        for(int b=0;b<=n;b++) {
            if(a == 0 || b == 0)
                dp[a][b] = 0;
            else if(seq[a-1] == rev[b-1])
                dp[a][b] = 1 + dp[a-1][b-1];
            else
                dp[a][b] = max(dp[a-1][b],dp[a][b-1]);
        }
    }

    return dp[n][n];
}

int solve(string seq, int n) {
    int dp[n+1][n+1];

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(seq[i-1] == seq[n-j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][n];
}
// Driver program to test above functions
int main()
{
	string seq = "G";
	int n = seq.size();
	cout << "The length of the LPS is "
		<< solve(seq, n);
	return 0;
}
