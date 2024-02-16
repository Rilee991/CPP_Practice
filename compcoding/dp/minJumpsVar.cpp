// arr n
// 1 2 3 4 5... n -> arr elems can be repeated not more than n, unsorted
// standing at index 0, have to go index n-1
// minimum jumps required to reach to exact at index n-1
// condition
// - if arr[currIndx] is odd then move 1
// - if arr[currIdx] is even then move exact arr[currIndx]

// Ques2
// condition
// - if arr[currIndx] is odd then move 1
// - if arr[currIdx] is even then move exact 3

// Ques3
// condition
// - if arr[currIndx] is odd then move 1
// - if arr[currIdx] is even then move exact 4

#include <iostream>
#include <vector>
using namespace std;

int solve1(vector<int> arr, int n) {
    int jumps = 0, jumpPoint = 0, reach = 0;

    for(int i=0;i<n;i++) {
        if(jumpPoint == n-1)    return jumps;
        reach = max(reach, i+(arr[i]&1 ? 1 : arr[i]));

        if(i == jumpPoint) {
            jumps++;
            jumpPoint = max(jumpPoint, reach);
        }
    }

    return jumpPoint != n-1 ? -1 : jumps;
}

int main() {
    vector<int> arr = {2,1,2,3,5,5,3};
    int n = arr.size();

    cout<<solve1(arr, n);
}
