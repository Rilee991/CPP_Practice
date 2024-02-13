#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void minCost (vector<vector<int>> citiesCost, int n, int h, int aCount, int bCount, string path, int cost, string &respath, int &ans) {
    if(n == 0) {
        reverse(path.begin(),path.end());
        if(ans > cost) {
            ans = cost;
            respath = path;
        }
        cout<<path<<" "<<cost<<"\n";
        return;
    }

    if(aCount < h)
        minCost(citiesCost, n-1, h, aCount+1, bCount, path+"A", cost + citiesCost[n-1][0], respath, ans);
    if(bCount < h)
        minCost(citiesCost, n-1, h, aCount, bCount+1, path+"B", cost + citiesCost[n-1][1], respath, ans);
}

int main() {
    vector<vector<int>> citiesCost = {{10, 20}, {30, 40}, {50, 90}, {34, 88}};
    string path = "";
    int ans = INT_MAX;

    minCost(citiesCost, citiesCost.size(), citiesCost.size()/2, 0, 0, "", 0, path, ans);
    cout<<"Result\n"<<path<<" "<<ans<<"\n";
    return 0;
}