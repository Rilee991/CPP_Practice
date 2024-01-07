#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

ll min(ll a, ll b) {
    return a < b ? b : a;
}

int main() {
    ll n = 10, r = 4;

    ll P[n+1][r+1];

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=min(i,r);j++) {
            if(j == 0) {
                P[i][j] = 1;
            } else if(j == 1) {
                P[i][j] = i;
            } else {
                P[i][j] = P[i-1][j] + j*P[i-1][j-1];
            }

            P[i][j+1] = 0;
        }
    }

    cout<<P[n][r];
}
