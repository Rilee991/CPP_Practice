// C++ program to find winner of game 
// if player can pick 1, x, y coins 
#include <iostream> 
using namespace std; 

// To find winner of game 
bool findWinner(int x, int y, int n) 
{ 
	// To store results 
	int dp[n + 1]; 

	// Initial values 
	dp[0] = false; 
	dp[1] = true; 

	// Computing other values. 
	for (int i = 2; i <= n; i++) { 

		// If A losses any of i-1 or i-x 
		// or i-y game then he will 
		// definitely win game i 
		if (i - 1 >= 0 and !dp[i - 1]) 
			dp[i] = true; 
		else if (i - x >= 0 and !dp[i - x]) 
			dp[i] = true; 
		else if (i - y >= 0 and !dp[i - y]) 
			dp[i] = true; 

		// Else A loses game. 
		else
			dp[i] = false; 
	} 

	// If dp[n] is true then A will 
	// game otherwise he losses 
	return dp[n]; 
} 

bool solve(int x, int y, int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++) {
        if(i == x || i == y) dp[i] = 1;
        else {
            dp[i] = 0;
            if(i-x >= 0 && dp[i-x] == 0) dp[i] = 1;
            else if(i-y >= 0 && dp[i-y] == 0) dp[i] = 1;
            else if(i-1 >= 0 && dp[i-1] == 0) dp[i] = 1;
        }
    }

    return dp[n];
}

// Driver program to test findWinner(); 
int main() 
{ 
	int x = 3, y = 4, n = 2; 
	if (solve(x, y, n)) 
		cout << 'A'; 
	else
		cout << 'B'; 

	return 0; 
} 
