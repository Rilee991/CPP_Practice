//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    struct count {
        int t;
        int f;
    };
public:
    int M = 1003;
    count eval(char ch1, char op, char ch2) {
        if(op == '|' && (ch1 == 'T' || ch2 == 'T')) return {1,0};
        if(op == '&' && ch1 == 'T' && ch2 == 'T')   return {1,0};
        if(op == '^' && ch1 != ch2) return {1,0};
        
        return {0,1};
    }
    
    count evalNum(count n1, char op, count n2) {
        if(op == '|') return {((n1.t%M*(n2.t%M+n2.f%M)%M)%M+(n1.f%M*n2.t%M)%M)%M,(n1.f%M*n2.f%M)%M};
        if(op == '&') return {(n1.t%M*n2.t%M)%M,((n1.f%M*(n1.t%M+n2.f%M)%M)%M+(n1.t%M*n2.f%M)%M)%M};
        return {((n1.t%M*n2.f%M)%M+(n1.f%M*n2.t%M)%M)%M,(n1.t%M*n2.t%M+n1.f%M*n2.f%M)%M};
    }
    count evalNum2(count n1, char op, count n2) {
        if (op == '|')
            return {((n1.t * n2.t) % M + (n1.t * n2.f) % M + (n1.f * n2.t) % M) % M, (n1.f * n2.f) % M};
        if (op == '&')
            return {(n1.t * n2.t) % M, ((n1.t * n2.f) % M + (n1.f * n2.t) % M + (n1.f * n2.f) % M) % M};
        // op == '^'
        return {(n1.t * n2.f + n1.f * n2.t) % M, (n1.t * n2.t + n1.f * n2.f) % M};
    }


    int countWays(int N, string S) {
        vector<vector<count>> dp(N, vector<count>(N, {0,0}));
        
        for(int gap=0;gap<N;gap+=2) {
            // cout<<"gap:"<<gap<<"\n";
            for(int i=0,j=gap;j<N;i+=2,j+=2) {
                // cout<<"i:"<<i<<", j:"<<j<<"\n";
                if(gap == 0) {
                    dp[i][j] = S[i] == 'T' ? count{1,0} : count{0,1};
                } else if(gap == 2) {
                    dp[i][j] = eval(S[i], S[i+1], S[j]);
                } else {
                    count res = {0,0};
                    for(int k=i;k<j;k+=2) {
                        // cout<<"k:"<<k<<"\n";
                        count num1 = dp[i][k];
                        char op = S[k+1];
                        count num2 = dp[k+2][j];
                        // cout<<"Evaluating for ("<<num1.t<<","<<num1.f<<")"<<op<<"("<<num2.t<<","<<num2.f<<")";
                        count temp = evalNum2(num1, op, num2);

                        // if(temp.t > res.t)  res = temp;
                        res.t += temp.t;
                        res.f += temp.f;
                    }
                    
                    dp[i][j] = res;
                }
                // cout<<"val:"<<dp[i][j].t<<", "<<dp[i][j].f<<"\n";
            }
            // cout<<"-----\n";
        }
        
        return dp[0][N-1].t;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    // cin>>t;
    // while(t--){
        int N = 35;
        // cin>>N;
        string S = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
        // cin>>S;
        
        Solution ob;
        // cout<<"Goig\n";
        cout<<ob.countWays(N, S)<<"\n";
    // }
    return 0;
}
// } Driver Code Ends