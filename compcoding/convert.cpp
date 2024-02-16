#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> arr, int i, int j) {
    if(i > j)   return 0;

    int mIdx = i;
    for(int it=i+1;it<=j;it++) {
        if(arr[mIdx] > arr[it]) mIdx = it;
    }

    int cost = arr[mIdx];

    for(int it=i;it<=j;it++) {
        arr[it] -= arr[mIdx];
    }

    int res = solve(arr, i, mIdx-1) + solve(arr, mIdx+1, j) + cost;
    cout<<"("<<i<<", "<<j<<"): "<<res<<"\n";
    return res;
}

int main() {
    vector<int> arr = {2,5,0,3,1};
    int n = arr.size();
    cout<<solve(arr, 0, n-1);

    return 0;
}