#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long int solve(int n) {
    if(n == 0)
        return 1;
    if(n == 1)
        return 2;
    if(n == 2)
        return 3;
    vector<long long int> f(n+1, 0);
    vector<long long int> b(n+1, 0);
    vector<long long int> t(n+1, 0);

    f[0] = 1;
    b[1] = t[1] = 1;
    f[2] = 3;

    for(int i=3;i<=n;i++) {
        f[i] = f[i-2] + b[i-1] + t[i-1];
        b[i] = f[i-1] + b[i-2];
        t[i] = f[i-1] + t[i-2];
    }

    return f[n];
}

int main() {
    int n;
    vector<long long int> res;

    while(true) {
        cin>>n;

        if(n == -1)
            break;

        // Call the function to compute the minimum number of moves
        long long int result = solve(n);
        // res.push_back(result);
        cout<<result<<"\n";
    }

    // for(long long int i: res)
    //     cout<<i<<"\n";

    return 0;
}