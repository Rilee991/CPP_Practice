#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;

int dp[1000][1000];

int solve(int arr[], int n, int k, int prod) {
    if(prod > k) return 0;
    else if(n == 0) return 1;

    if(dp[prod][n] != -1)   return dp[prod][n];

    int w1 = solve(arr,n-1,k,prod*arr[n-1]);
    int w2 = solve(arr,n-1,k,prod);

    return dp[prod][n] = w1+w2;
}

int solve2(int arr[], int n, int k, int prod) {
    if(prod > k) return 0;
    else if(n == 0) return 1;

    int w1 = solve(arr,n-1,k,prod*arr[n-1]);
    int w2 = solve(arr,n-1,k,prod);

    return w1+w2;
}

int solve3(int arr[], int n, int k, int p) {
    if(p > k)   return 0;
    if(n == 0)  return 1;

    if(dp[n][p] != -1)  return dp[n][p];

    int w1 = solve3(arr, n-1, k, p*arr[n-1]);
    int w2 = solve3(arr, n-1, k, p);

    return dp[n][p] = w1 + w2;
}

int main() {
    int arr[] = { 1,2,3,4 };
    int n = sizeof(arr)/sizeof(int);
    int k = 10;
    memset(dp, -1, sizeof dp);


    auto start2 = chrono::high_resolution_clock::now();
    cout<<solve3(arr,n,k,1)<<"--2\n";
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double,milli> d2 = end2-start2;
    cout<<d2.count()<<"\n";

    // auto start = chrono::high_resolution_clock::now();
    // cout<<solve(arr,n,k,1)<<"--1\n";
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double,milli> d = end-start;
    // cout<<d.count()<<"\n";

    return 0;
}