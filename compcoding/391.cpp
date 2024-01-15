#include <iostream> 
#include <vector> 
#include <climits>
using namespace std; 

int solve(vector<vector<int> > a, vector<vector<int> > t, int cl, int cs, int x1, int x2, int n, vector<vector<int>> &dp) {
	if(cs == n)	return cl == 0 ? x1 : x2;

	if(dp[cl][cs] != -1)	return dp[cl][cs];

	int w1 = solve(a,t,cl,cs+1,x1,x2,n,dp) + a[cl][cs];
	int w2 = cs == n-1 ? INT_MAX : solve(a,t,!cl,cs+1,x1,x2,n,dp) + a[cl][cs] + t[cl][cs+1];

	return dp[cl][cs] = min(w1,w2);
}

int solveTab (vector<vector<int> > a, vector<vector<int> > t, int e1, int e2, int x1, int x2, int n) {
	vector<vector<int> > dp(2,vector<int>(n+1,0));

	dp[0][n] = x1;
	dp[1][n] = x2;

	for(int cl=0;cl<=1;cl++) {
		for(int cs=n-1;cs>=0;cs--) {
			int w1 = dp[cl][cs+1]+a[cl][cs];
			int w2 = cs == n-1 ? INT_MAX : dp[!cl][cs+1] + a[cl][cs] + t[cl][cs+1];

			dp[cl][cs] = min(w1,w2);
		}
	}

	return min(dp[0][0]+e1,dp[1][0]+e2);
}

int main() { 
	int n = 4; // number of statin 
	vector<vector<int> > a 
		= { { 4, 5, 3, 2 }, { 2, 10, 1, 4 } }; 
	vector<vector<int> > t 
		= { { 0, 7, 4, 5 }, { 0, 9, 2, 8 } }; 

	int e1 = 10; 
	int e2 = 12; 
	int x1 = 18; 
	int x2 = 7;

	vector<vector<int> > dp(2,vector<int>(n,-1));
	cout<<solveTab(a,t,e1,e2,x1,x2,4);

	// cout<<min(solve(a,t,0,0,x1,x2,4,dp)+e1, solve(a,t,1,0,x1,x2,4,dp)+e2);
}
