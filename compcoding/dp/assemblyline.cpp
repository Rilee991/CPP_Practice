#include <iostream> 
#include <vector> 
using namespace std; 

int fun(vector<vector<int> > a, vector<vector<int> > t, 
		int cl, int cs, int x1, int x2, int n) 
{ 
	// base case 
	if (cs == n - 1) { 
		if (cl == 0) { // exiting from (current) line =0 
			return x1; 
		} 
		else // exiting from line 2 
			return x2; 
	} 
	// continue on same line 
	int same 
		= fun(a, t, cl, cs + 1, x1, x2, n) + a[cl][cs + 1]; 
	// continue on different line 
	int diff = fun(a, t, !cl, cs + 1, x1, x2, n) 
			+ a[!cl][cs + 1] + t[cl][cs + 1]; 

	return min(same, diff); 
} 

int solve(int n, vector<vector<int> > a, vector<vector<int> > t, int x1, int x2, int cs, int cl) {
    int currCost = a[cl][cs];

    if(cs+1 == n) {
        return currCost + (cl == 0 ? x1 : x2);
    }

    int sameStation = solve(n, a, t, x1, x2, cs+1, cl);
    int diffStation = solve(n, a, t, x1, x2, cs+1, !cl) + t[cl][cs+1];

    return min(sameStation, diffStation) + currCost;
}

int solveTab(int n, vector<vector<int> > a, vector<vector<int> > t, int x1, int x2, int e1, int e2) {
    int l0prev = e1 + a[0][0];
    int l1prev = e2 + a[1][0];

    for(int i=1;i<n;i++) {
        int l0curr = min(l0prev, l1prev+t[1][i]) + a[0][i];
        int l1curr = min(l1prev, l0prev+t[0][i]) + a[1][i];

        l0prev = l0curr;
        l1prev = l1curr;
    }

    return min(l0prev+x1, l1prev+x2);
}

int main() 
{ 
	int n = 4; // number of statin 
	vector<vector<int> > a 
		= { { 4, 5, 3, 2 }, { 2, 10, 1, 4 } }; 
	vector<vector<int> > t 
		= { { 0, 7, 4, 5 }, { 0, 9, 2, 8 } }; 

	int e1 = 10; 
	int e2 = 12; 
	int x1 = 18; 
	int x2 = 7; 

    // int res = min(e1 + solve(n, a, t, x1, x2, 0, 0), e2 + solve(n, a, t, x1, x2, 0, 1));
    // cout<<res;
    cout<<solveTab(n, a, t, x1, x2, e1, e2);
	// // entry from 1st line 
	// int x = fun(a, t, 0, 0, x1, x2, n) + e1 + a[0][0]; 
	// // entry from 2nd line 
	// int y = fun(a, t, 1, 0, x1, x2, n) + e2 + a[1][0]; 
	// cout << min(x, y) << endl; 
}
