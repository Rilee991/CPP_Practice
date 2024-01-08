#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

int getMaxGold(vector<vector<int>> gold, int n, int m) {
    int res = 0;

    for(int c=1;c<m;c++) {
        for(int r=0;r<n;r++) {
            int topLeft = r-1>=0 && c-1>=0 ? gold[r-1][c-1] : 0;
            int left = c-1>=0 ? gold[r][c-1] : 0;
            int downLeft = r+1<n && c-1>=0 ? gold[r+1][c-1] : 0;

            gold[r][c] += max(topLeft, max(left, downLeft));
            res = max(res, gold[r][c]);
        }
    }
    
    return res;
}

int main() {
    vector<vector<int>> gold { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getMaxGold(gold, n, m);
}
