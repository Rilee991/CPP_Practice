// arr n
// 1 2 3 4 5... n -> arr elems can be repeated not more than n, unsorted
// standing at index 0, have to go index n-1
// minimum jumps required to reach to exact at index n-1
// condition
// - if currIndx is odd then move 1
// - if currIdx is even then move max of arr[currIndx]

// Ques2
// condition
// - if arr[currIndx] is odd then move 1
// - if arr[currIdx] is even then move exact 3

// Ques3
// condition
// - if arr[currIndx] is odd then move 1
// - if arr[currIdx] is even then move exact 4

// Graph
// n number of nodes
// some nodes are unidirectional and some are bidirectional
// cost of unidirectional node - 10rs, bidirectional - 5rs
// given a src and dest.
// 1. solve such that minimum of nodes are crossed
// 2. solve such that minimum cost is incurred
// n = 6, [1,2,3,4,5,6] (1,3) (3,4), (4,3) (2,4) (4,2) (1,2) (2,1) (1,6) (2,5) (5,6) //1,2,3 wala is uni and 4,5,6 wala is bi
// src = 1, dest = 5 - (ans. case1: 1, case2: 15)
// src = 3, dest = 5 - (ans. case1: 2, case2: 20)
// src = 6, dest = 4 - (ans. case1: -1, case2: -1)

#include <iostream>
#include <vector>
using namespace std;
// odd - 1, even - arr[i]
int solve1(vector<int> arr, int n) {
    int jumps = 0, jumpPoint = 0, reach = 0;

    for(int i=0;i<n;i++) {
        if(jumpPoint == n-1)    return jumps;
        reach = max(reach, i+(i&1 ? 1 : arr[i]));

        if(i == jumpPoint) {
            jumps++;
            jumpPoint = max(jumpPoint, reach);
        }
    }

    return jumpPoint < n-1 ? -1 : jumps;
}

int main() {
    vector<int> arr = {2,1,2,3,5,5,3};
    int n = arr.size();

    cout<<solve1(arr, n);
}
