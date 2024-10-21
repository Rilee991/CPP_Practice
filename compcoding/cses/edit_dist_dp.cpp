#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfs(string &str1, int n, string &str2, int m) {
    if(n == 0)
        return m;
    if(m == 0)
        return n;
    
    if(str1[n-1] == str2[m-1])
        return dfs(str1, n-1, str2, m-1);
    
    int w1 = dfs(str1, n-1, str2, m);
    int w2 = dfs(str1, n, str2, m-1);
    int w3 = dfs(str1, n-1, str2, m-1);

    return min(w1, min(w2, w3)) + 1;
}

// Function to calculate the edit distance (to be implemented)
int editDistance(string &str1, string &str2) {
    vector<int> curr(str2.size()+1);
    vector<int> prev(str2.size()+1);

    for(int n=0;n<=str1.size();n++) {
        for(int m=0;m<=str2.size();m++) {
            if(n == 0) {
                curr[m] = m;
            } else if(m == 0) {
                curr[m] = n;
            } else if(str1[n-1] == str2[m-1]) {
                curr[m] = prev[m-1];
            } else {
                int w1 = prev[m];
                int w2 = curr[m-1];
                int w3 = prev[m-1];

                curr[m] = min(w1, min(w2, w3)) + 1;
            }
        }

        prev = curr;
    }

    return curr[str2.size()];
}

int main() {
    string str1, str2;

    // Input strings
    cin >> str1;
    cin >> str2;

    // Call the function to compute the edit distance
    int result = editDistance(str1, str2);

    // Output the result
    cout << result << endl;

    return 0;
}
