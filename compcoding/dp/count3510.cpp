//{ Driver Code Starts
// Driver Code
#include <iostream>
#include <climits>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int solve(long long int n) {
        if(n == 0)  return 0;
        if(n < 3)   return INT_MAX;
        if(n == 3 || n == 5 || n == 10) return 1;
        
        long long int res = 0;

        long long int w1 = n - 3 >= 0 ? solve(n-3) : INT_MAX;
        if(w1 != INT_MAX) res += w1;

        long long int w2 = n - 5 >= 0 ? solve(n-5) : INT_MAX;
        if(w2 != INT_MAX) res += w2;

        long long int w3 = n - 10 >= 0 ? solve(n-10) : INT_MAX;
        if(w3 != INT_MAX) res += w3;
        
        if(w1 == w2 && w2 == w3 && w1 == INT_MAX)   return INT_MAX;
        
        return res + 1;
    }

    long long int count(long long int n) {
        long long int dp[n+1];
        
        for(int i=0;i<=n;i++) {
            if(i == 0) dp[i] = 0;
            else if(i < 3) dp[i] = INT_MAX;
            else if(i == 3 || i == 5) dp[i] = 1;
            else {
                long long int res = 0;

                long long int w1 = n - 3 >= 0 ? dp[n-3] : INT_MAX;
                if(w1 != INT_MAX) res += w1;
        
                long long int w2 = n - 5 >= 0 ? dp[n-5] : INT_MAX;
                if(w2 != INT_MAX) res += w2;
        
                long long int w3 = n - 10 >= 0 ? dp[n-10] : INT_MAX;
                if(w3 != INT_MAX) res += w3;
                
                if(w1 == w2 && w2 == w3 && w1 == INT_MAX)   dp[i] = INT_MAX;
                else dp[i] = res + 1;
            }
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends