#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

long long M = 1e9+7;

void takeArrayInput(vector<int> &coins, int n) {
    for(int i=0;i<n;i++)
        cin>>coins[i];
}

int dfs(int n) {
    if(n == 0)
        return 0;
    if(n <= 9)
        return 1;
    
    int temp = n;
    int largest = temp%10;

    while(temp) {
        largest = max(largest, temp%10);
        temp = temp/10;
    }

    return 1 + dfs(n-largest);
}

int solve(int n) {
    return dfs(n);
}

int main() {
    int n;
    cin>>n;

    cout<<solve(n);
    return 0;
};