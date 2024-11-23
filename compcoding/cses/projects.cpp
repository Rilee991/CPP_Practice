#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// Function to calculate the maximum reward (to be implemented)
long long dfs(vector<tuple<int, int, int>> &projects, int n, vector<tuple<int,int,int>> temp) {
    if(n == 0) {
        int sum = 0;
        for(int i=0;i<temp.size();i++) {
            sum += get<2>(temp[i]);
            cout<<get<0>(temp[i])<<" "<<get<1>(temp[i])<<" "<<get<2>(temp[i])<<"\n";
        }
        cout<<"Sum:"<<sum;
        cout<<"\n***********************\n";
        return 0;
    }
    
    long long take = 0; //dfs(projects, n-1, temp) + get<2>(projects[n-1]);
    int nextIdx = 0;
    for(int i=n-1; i>0; i--) {
        if(get<1>(projects[i-1]) < get<0>(projects[n-1])) {
            temp.push_back(projects[n-1]);
            take = max(take, dfs(projects, i, temp));
            temp.pop_back();
        }
    }

    take += get<2>(projects[n-1]);

    long long noTake = dfs(projects, n-1, temp);

    return max(take, noTake);
}

long long maxReward(vector<tuple<int, int, int>> &projects) {
    sort(projects.begin(), projects.end(), [](tuple<int,int,int> t1, tuple<int,int,int> t2) {
        if(get<1>(t1) == get<1>(t2))
            return get<0>(t1) > get<0>(t2);
        return get<1>(t1) < get<1>(t2);
    });

    vector<long long> dp(projects.size()+1, 0);

    for(int n=1;n<=projects.size();n++) {
        long long take = 0; //dfs(projects, n-1, temp) + get<2>(projects[n-1]);
        int nextIdx = 0;
        //Here we are searching for next first interval that doesn't overlap with n
        // basically a searching problem -> this can be solved in log(n) time.
        int lo = 1, hi = n-1, i = 0;

        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(get<1>(projects[mid-1]) < get<0>(projects[n-1])) {
                i = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // for(; i>0; i--) {
        //     if(get<1>(projects[i-1]) < get<0>(projects[n-1])) {
        //         // temp.push_back(projects[n-1]);
        //         take = max(take, dp[i]);
        //         // temp.pop_back();
        //     }
        // }

        take += dp[i] + get<2>(projects[n-1]);

        long long noTake = dp[n-1];

        dp[n] = max(take, noTake);
    }

    return dp[projects.size()];
    // return dfs(projects, projects.size(), {});
}

int main() {
    int n;

    // Input the number of projects
    cin >> n;

    vector<tuple<int, int, int>> projects(n);

    // Input each project's start day, end day, and reward
    for (int i = 0; i < n; ++i) {
        int a, b, p;
        cin >> a >> b >> p;
        projects[i] = make_tuple(a, b, p);
    }

    // Calculate the maximum reward
    long long result = maxReward(projects);

    // Output the result
    cout << result << endl;

    return 0;
}
