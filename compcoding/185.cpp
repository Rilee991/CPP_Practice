// C++ program for Minimum swap required
// to convert binary tree to binary search tree
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Inorder Traversal of Binary Tree
void inorder(int a[], std::vector<int> &v, 
						int n, int index)
{
	// if index is greater or equal to vector size
	if(index >= n)
		return;
	inorder(a, v, n, 2 * index + 1);
	
	// push elements in vector
	v.push_back(a[index]);
	inorder(a, v, n, 2 * index + 2);
}

// Function to find minimum swaps to sort an array
int minSwaps(std::vector<int> &v)
{
	std::vector<pair<int,int> > t(v.size());
	int ans = 0;
	for(int i = 0; i < v.size(); i++)
		t[i].first = v[i], t[i].second = i;
	
	sort(t.begin(), t.end());
	for(int i = 0; i < t.size(); i++)
	{
		// second element is equal to i
		if(i == t[i].second)
			continue;
		else
		{
			// swapping of elements
			swap(t[i].first, t[t[i].second].first);
			swap(t[i].second, t[t[i].second].second);
		}
		
		// Second is not equal to i
		if(i != t[i].second)
			--i;
		ans++;
	}
	return ans;
}

void inorder(int arr[], int i, int n, vector<int> &res) {
    if(i >= n)  return;

    inorder(arr,2*i+1,n,res);
    res.push_back(arr[i]);
    inorder(arr,2*i+2,n,res);
}

int minSwaps2(int arr[], int n) {
    vector<int> in;
    inorder(arr,0,n,in);

    vector<pair<int,int>> sorted(n);
    for(int i=0;i<n;i++) sorted[i] = {in[i],i};

    sort(sorted.begin(), sorted.end());
    // for(auto st: sorted)cout<<st.first<<" "<<st.second<<"\n";

    int res = 0;

    for(int i=0;i<n;i++) {
        if(sorted[i].second == i)
            continue;
        swap(sorted[i],sorted[sorted[i].second]);
        if(sorted[i].second != i) i--;

        res++;
    }

    return res;
}

// Driver code
int main()
{
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	// inorder(a, v, n, 0);
	// cout << minSwaps(v) << endl;
    cout<<minSwaps2(a,n);
}

// This code is contributed by code_freak
