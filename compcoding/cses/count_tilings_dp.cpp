#include<iostream>
using namespace std;

#define int long long
#define endl '\n'

int dp[1003][1030], n,m;
const int md = 1e9+7;

void solve(int x = 0, int y = 0, int mask = 0, int next_mask = 0) {
    if (x == n)
        return;
    if (y >= m)
        (dp[x+1][next_mask] += dp[x][mask])%=md;
    else
    {
        int my_mask = 1 << y;
        if (mask & my_mask)
            solve (x, y+1, mask, next_mask);
        else
        {
            solve (x, y+1, mask, next_mask | my_mask);
            if (y+1 < m && ! (mask & (my_mask << 1)))
                solve (x, y+2, mask, next_mask);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>m>>n;
    dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1<<m); j++) {
			solve(i, 0, j, 0);
		}
	}    
	cout<<dp[n][0];
}

// #include <iostream>
// #include <vector>

// using namespace std;

// const int MOD = 1000000007;

// void getNextMasks(int rows, int cols, int currCol, int currRow, int currColMask, int nextMask, vector<int> &nextMasks) {
//     if(currRow >= rows) {
//         nextMasks.push_back(nextMask);
//         return;
//     }

//     if(currColMask&(1<<currRow)) {
//         getNextMasks(rows, cols, currCol, currRow+1, currColMask, nextMask^(1<<currRow), nextMasks);

//         if(currRow + 1 < rows && currColMask&(1<<(currRow+1))) {
//             getNextMasks(rows, cols, currCol, currRow+2, currColMask, nextMask, nextMasks);
//         }
//     } else {
//         getNextMasks(rows, cols, currCol, currRow + 1, currColMask, nextMask, nextMasks);
//     }
// }

// int dfs(int rows, int cols, int currCol, int currColMask) {
//     if(currCol == cols) {
//         return currColMask == 0;
//     }

//     vector<int> nextMasks;
//     getNextMasks(rows, cols, currCol, 0, currColMask, (1<<(currCol+1)) - 1, nextMasks);
//     int res = 0;

//     for(int nextMask: nextMasks) {
//         res += dfs(rows, cols, currCol + 1, nextMask);
//     }

//     return res;
// }

// // Function to calculate the number of ways (to be implemented)
// int calculateWays(int n, int m) {
//     return dfs(n, m, 0, (1<<n)-1);
// }

// int main() {
//     int n, m;

//     // Input the two integers n and m
//     cin >> n >> m;

//     // Calculate the number of ways
//     int result = calculateWays(n, m);

//     // Output the result modulo 10^9+7
//     cout << result << endl;

//     return 0;
// }
