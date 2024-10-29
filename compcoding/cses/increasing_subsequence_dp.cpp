#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the length of the longest increasing subsequence (to be implemented)
int longestIncreasingSubsequence(vector<int> &arr) {
    // 3 5 6 8
    vector<int> coll;

    coll.push_back(arr[0]);

    for(int i=1;i<arr.size();i++) {
        if(coll.back() < arr[i]) {
            coll.push_back(arr[i]);
        } else {
            auto it = lower_bound(coll.begin(), coll.end(), arr[i]);
            int idx = it - coll.begin();

            coll[idx] = arr[i];
        }
    }

    return coll.size();
}
// 10 20 30 40 1 2 3 4 5 6 7
// 1 20 30 40
int main() {
    int n;

    // Input the size of the array
    cin >> n;

    vector<int> arr(n);

    // Input the contents of the array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Calculate the length of the longest increasing subsequence
    int result = longestIncreasingSubsequence(arr);

    // Output the result
    cout << result << endl;

    return 0;
}
