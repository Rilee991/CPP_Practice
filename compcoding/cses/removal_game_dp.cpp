#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the maximum possible score for the first player (to be implemented)
long long dfs(vector<int> &nums, int i, int j) {
    if(i > j)
        return 0;

    long long left = nums[i] + min(dfs(nums, i+2, j), dfs(nums, i+1, j-1));
    long long right = nums[j] + min(dfs(nums, i, j-2), dfs(nums, i+1, j-1));

    return max(left, right);
}

long long maxScoreFirstPlayer(vector<int> &nums) {
    vector<vector<long long>> dp(nums.size(), vector<long long>(nums.size(), 0));
    vector<long long> curr(nums.size(), 0);
    vector<long long> next(nums.size(), 0);
    vector<long long> nexter(nums.size(), 0);

    for(int i=nums.size();i>=0;i--) {
        for(int j=0;j<nums.size();j++) {
            if(i <= j) {
                long long left = nums[i] + min(i+2 < nums.size() ? nexter[j] : 0, (i+1 < nums.size() && j-1 >= 0) ? next[j-1] : 0);
                long long right = nums[j] + min(j-2 >= 0 ? curr[j-2] : 0, (i+1 < nums.size() && j-1 >= 0) ? next[j-1] : 0);

                curr[j] = max(left, right);
            }
        }

        nexter = next;
        next = curr;
    }

    return curr[nums.size()-1];
    // return dfs(nums, 0, nums.size()-1);
}

int main() {
    int n;

    // Input the size of the list
    cin >> n;

    vector<int> nums(n);
    
    // Input the contents of the list
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Calculate the maximum score for the first player
    long long result = maxScoreFirstPlayer(nums);

    // Output the result
    cout << result << endl;

    return 0;
}
