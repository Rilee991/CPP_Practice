#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> arr, int n, int k) {
    sort(arr.begin(), arr.end());

    int res = 0, m = 1;
    vector<int> temp;
    temp.push_back(arr[0]);

    for(int i=1;i<n;i++) {
        if(arr[i]-temp.front() <= k) {
            temp.push_back(arr[i]);
            m++;
        } else {
            res = max(res, m);

            while(m > 0 && arr[i]-temp.front() > k) {
                temp.pop_back();
                m--;
            }

            temp.push_back(arr[i]);
            m++;
        }
    }

    res = max(res, m);

    return n-res;
}

int solve2(vector<int> arr, int n, int k) {
    sort(arr.begin(),arr.end());

    int i = 0, j = 0, res = 0;

    while(j < n) {
        while(j < n && arr[j]-arr[i] <= k) j++;

        res = max(res, j-i);

        while(j < n && arr[j]-arr[i] > k) i++;
    }

    res = max(res, j-i);
    return n-res;
}

int main() {
    vector<int> arr = { 1, 2,2,2,4};
    int k = 4;
    int n = arr.size();

    cout<<solve2(arr, n, k);


    // sort(arr.begin(),arr.end());

    // queue<int> q;
    // int res = INT_MAX;
    
    // for(int i=0;i<n;i++) {
    //     if(q.empty()) {
    //         q.push(arr[i]);
    //     } else if(arr[i] - q.front() <= k) {
    //         q.push(arr[i]);
    //     } else {
    //         res = min(res, n-(int)q.size());
    //         while(!q.empty() && arr[i]-q.front() > k)
    //             q.pop();
    //         q.push(arr[i]);
    //     }
    // }

    // res = min(res, n-(int)q.size());

    // cout<<res;
}
