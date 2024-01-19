// A C++ program to find Largest rectangular
// sub-matrix whose sum is 0
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> sumZeroMatrix(vector<vector<int>> arr, int n, int m) {
    int sc = -1, sr = -1, ec = -1, er = -1;
    for(int c1=0;c1<m;c1++) {
        for(int c2=c1;c2<m;c2++) {
            int colSum[n];
            for(int r1=0;r1<n;r1++) {
                colSum[r1] = c2 == c1 ? arr[c2][r1] : colSum[r1] + arr[c2][r1];
            }
            map<int,int> mp;

            for(int i=0;i<n;i++) {
                if(mp.find(colSum[i]) == mp.end()) {
                    mp[colSum[i]] = i;
                } else {
                    cout<<colSum[i]<<"...\n";
                    sc = c1;
                    ec = c2;
                    sr = mp[colSum[i]]+1;
                    er = i;

                    return { sr, er, sc, ec };
                }
            }
        }
    }

    return { -1 };
}

// Driver program to test above functions
int main() {
	vector<vector<int>> arr = { { 9, 7, 16, 5 },
					{ 1, -6, -7, 3 },
					{ 1, 8, 7, 9 },
					{ 7, -2, 0, 10 } };

	int row = arr.size(), col = arr[0].size();
	vector<int> res = sumZeroMatrix(arr, row, col);

    if(res[0] == -1) cout<<"No elem found\n";
    else {
        cout<<"sr:"<<res[0]<<" er:"<<res[1]<<" sc:"<<res[2]<<" ec:"<<res[3]<<"\n";
        for(int i=res[0];i<=res[1];i++) {
            for(int j=res[2];j<=res[3];j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
	return 0;
}
