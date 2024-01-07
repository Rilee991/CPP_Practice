#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = { 1, 5, 6, 2, 8};
    int k = 2;
    int n = arr.size();

    sort(arr.begin(),arr.end());

    queue<int> q;
    int res = INT_MAX;
    
    for(int i=0;i<n;i++) {
        if(q.empty()) {
            q.push(arr[i]);
        } else if(arr[i] - q.front() <= k) {
            q.push(arr[i]);
        } else {
            res = min(res, n-(int)q.size());
            while(!q.empty() && arr[i]-q.front() > k)
                q.pop();
            q.push(arr[i]);
        }
    }

    res = min(res, n-(int)q.size());

    cout<<res;
}
