#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // Memoization cache using unordered_map to store computed states
    unordered_map<int, pair<int,int>> memo;

    // Recursive function with memoization
    pair<int,int> solve(int mask, int limit, vector<int>& weights) {
        // Base case: if all people are assigned
        if (mask == 0) {
            return {0, 0};
        }

        // Check if the current state is already computed
        if (memo.count(mask)) {
            return memo[mask];
        }

        // Initialize with worst possible values
        pair<int,int> best = {INT_MAX, 0};

        // Try adding each unassigned person to the current ride
        for (int bit = 0; bit < weights.size(); bit++) {
            if ((mask & (1 << bit)) == 0) continue; // Skip if person already assigned
            
            // Remove this person from the mask
            int newMask = mask ^ (1 << bit);
            
            // Solve for the remaining people
            auto p = solve(newMask, limit, weights);
            int prevRides = p.first;
            int prevWeight = p.second;
            
            // Two scenarios: 
            // 1. Add to current ride if possible
            if (prevWeight + weights[bit] <= limit) {
                best = min(best, {prevRides, prevWeight + weights[bit]});
            }
            
            // 2. Start a new ride
            best = min(best, {prevRides + 1, weights[bit]});
        }

        // Memoize and return the result
        return memo[mask] = best;
    }

public:
    int minElevatorRides(int limit, vector<int>& weights) {
        // Start with all people unassigned (full mask)
        int fullMask = (1 << weights.size()) - 1;
        
        // Call recursive function
        return solve(fullMask, limit, weights).first + 1;
    }
};

int main() {
    int n, limit;

    // Input the number of people and maximum allowed weight
    cin >> n >> limit;

    vector<int> weights(n);

    // Input the weight of each person
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // Calculate the minimum number of rides
    Solution solution;
    int result = solution.minElevatorRides(limit, weights);

    // Output the result
    cout << result << endl;

    return 0;
}
