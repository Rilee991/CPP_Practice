#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;

int dp[1000][1000];

int solve(int arr[], int n, int cc) {
    if(n == 0)  return 0;

    if(dp[n][cc] != -1) return dp[n][cc];

    int w1 = cc < 2 ? arr[n-1] + solve(arr,n-1,cc+1) : 0;
    int w2 = solve(arr,n-1,0);

    return dp[n][cc] = max(w1,w2);
}

int maxi(int a, int b, int c) {
    return max(a,max(b,c));
}

int tab(int arr[], int n) {
    if(n == 0)  return 0;

    int dp[n];

    if(n >= 1)
        dp[0] = arr[0];

    if(n >= 2)
        dp[1] = arr[0]+arr[1];
    
    if(n > 2)
        dp[2] = maxi(arr[2]+arr[1],dp[0]+arr[2],dp[1]);

    for(int i=3;i<n;i++) {
        dp[i] = maxi(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i],dp[i-1]);
    }

    return dp[n-1];
}

int solve2(int arr[], int n) {
    int sum0 = arr[0];
    if(n == 1)  return sum0;
    int sum1 = arr[0] + arr[1];
    if(n == 2)  return sum1;
    int sum2 = max(sum1, max(arr[1]+arr[2], arr[2]+sum0));
    if(n == 3)  return sum2;
    int sum3 = max(sum2, max(arr[3]+arr[2]+sum0, arr[3]+sum1));
    if(n == 4)  return sum3;
    

    for(int i=4;i<n;i++) {
        // cout<<sum0<<", "<<sum1<<", "<<sum2<<", "<<sum3<<"\n";
        sum0 = sum1;
        sum1 = sum2;
        sum2 = sum3;
        sum3 = max(sum2, max(arr[i-1]+arr[i]+sum0, arr[i]+sum1));
        // cout<<sum0<<", "<<sum1<<", "<<sum2<<", "<<sum3<<"\n";
    }

    return sum3;
}

int solve_1(int arr[], int n) {
    int s1 = 0, s2 = 0, s3 = 0;
    if(n >= 1)  s1 = arr[0];
    if(n >= 2)  s2 = arr[0]+arr[1];
    if(n >= 3)  s3 = max(arr[2]+arr[1], max(arr[2]+arr[0],s2));

    if(n == 1)  return s1;
    if(n == 2)  return s2;
    if(n == 3)  return s3;

    for(int i=3;i<n;i++) {
        int sum = max(arr[i]+arr[i-1]+s1,max(arr[i]+s2,s3));
        s1 = s2;
        s2 = s3;
        s3 = sum;
    }

    return s3;
}

int main() {
    int arr[] = { 100, 1000, 100, 1000, 1 };
    int n = sizeof(arr)/sizeof(int);
    memset(dp, -1, sizeof dp);

    cout<<solve_1(arr,n);

    // auto start2 = chrono::high_resolution_clock::now();
    // cout<<solve2(arr,n)<<"--2\n";
    // auto end2 = chrono::high_resolution_clock::now();
    // chrono::duration<double,milli> d2 = end2-start2;
    // cout<<d2.count()<<"\n";

    return 0;
}