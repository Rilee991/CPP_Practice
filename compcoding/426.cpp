// A Naive Recursive C++ program 
// to count derangements
#include <iostream>
#include <vector>
using namespace std;

int countDer(int n, vector<int> &dp) {
    if(n <= 1)  return 0;
    if(n == 2)  return 1;
    if(n == 3)  return 2;

    if(dp[n] != -1) return dp[n];

    return dp[n] = (n-1)*(countDer(n-1, dp)+countDer(n-2, dp));
}

// Driver Code
int main() {
	int n = 45;
    vector<int> dp(n+1, -1);
    dp[0] = dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
	cout << "Count of Derangements is "
		<< countDer(n, dp);
	return 0;
}
