#include <iostream>
#include <vector>
using namespace std;

// Helper function to calculate the maximum number of pages
int dfs(int n, int amount, vector<int>& prices, vector<int>& pages, vector<vector<int>> &dp) {
    if(n == 0 || amount == 0)
        return 0;

    if(dp[n][amount] != -1)
        return dp[n][amount];
    
    int take = amount-prices[n-1] >= 0 ? dfs(n-1, amount-prices[n-1], prices, pages, dp) + pages[n-1] : 0;
    int noTake = dfs(n-1, amount, prices, pages, dp);

    return dp[n][amount] = max(take, noTake);
}

int max_pages(int n, int amount, vector<int>& prices, vector<int>& pages) {
    // vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
    vector<int> curr(amount+1, 0);
    vector<int> prev(amount+1, 0);

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=amount;j++) {
            if(i == 0 || j == 0) {
                curr[j] = 0;
            } else if(j-prices[i-1] < 0) {
                curr[j] = prev[j];
            } else {
                int take = prev[j-prices[i-1]] + pages[i-1];
                int noTake = prev[j];

                curr[j] = max(take, noTake);
            }
        }

        prev = curr;
    }

    return curr[amount];
}

int main() {
    int n, x;
    
    // Reading input for number of books and max total price
    cin >> n >> x;
    
    vector<int> prices(n);  // Array to store prices of the books
    vector<int> pages(n);   // Array to store pages of the books
    
    // Reading prices of the books
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    // Reading number of pages of the books
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    // Calling the helper function to get the maximum number of pages
    int result = max_pages(n, x, prices, pages);
    
    // Output the result
    cout << result << endl;
    
    return 0;
}
