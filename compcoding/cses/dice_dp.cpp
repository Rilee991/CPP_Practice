// #include <iostream>
// #include <vector>
// #include <climits>
// #include <set>
// using namespace std;

// long long M = 1e9+7;

// void takeArrayInput(vector<int> &coins, int n) {
//     for(int i=0;i<n;i++)
//         cin>>coins[i];
// }

// int solve(int n) {

// }

// int main() {
//     int n;
//     cin>>n;

//     cout<<solve(n);
//     return 0;
// };

#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp;
long long M = 1e9+7;

long long dfs(int n) {
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];
    
    long long res = 0;
    
    for(int i=1;i<=6;i++)
        res = (res + (dfs(n-i)%M))%M;
    
    return dp[n] = res;
}

int solve(int n) {
    dp.resize(n+1, -1);

    return dfs(n);
}

int main() {
    int n;
    cin>>n;

    cout<<solve(n);
    return 0;
};
