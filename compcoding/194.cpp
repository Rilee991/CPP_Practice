// C++ program to print all paths with sum k.
#include <iostream>
#include <vector>
using namespace std;

// utility function to print contents of
// a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
	for (int j = i; j < v.size(); j++)
		cout << v[j] << " ";
	cout << endl;
}

// binary tree node
struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

// This function prints all paths that have sum k
void printKPathUtil(Node* root, vector<int>& path, int k)
{
	// empty node
	if (!root)
		return;

	// add current node to the path
	path.push_back(root->data);

	// check if there's any k sum path
	// in the left sub-tree.
	printKPathUtil(root->left, path, k);

	// check if there's any k sum path
	// in the right sub-tree.
	printKPathUtil(root->right, path, k);

	// check if there's any k sum path that
	// terminates at this node
	// Traverse the entire path as
	// there can be negative elements too
	int f = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		f += path[j];

		// If path sum is k, print the path
		if (f == k)
			printVector(path, j);
	}

	// Remove the current element from the path
	path.pop_back();
}

void pre(Node* root, int curr, int sum, vector<int> path, vector<vector<int>> &res) {
    if(!root)   return;

    // Choice 1 considering
    path.push_back(root->data);
    curr += root->data;

    if(sum == curr) {
        res.push_back(path);
    }
    pre(root->left, curr, sum, path, res);
    pre(root->right, curr, sum, path, res);

    // Choice 2 not considering
    path = {};
    curr = 0;

    pre(root->left, curr, sum, path, res);
    pre(root->right, curr, sum, path, res);
}

// A wrapper over printKPathUtil()
void printKPath(Node* root, int k)
{
	vector<int> path;
	printKPathUtil(root, path, k);
}


void solve(Node* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;

    pre(root, 0, sum, path, res);

    for(auto it: res) {
        for(auto jt: it)
            cout<<jt<<" ";
        cout<<"\n";
    }
}

// Driver code
int main()
{
	Node* root = new Node(1);
	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(1);
	root->left->right->left = new Node(1);
	root->right = new Node(-1);
	root->right->left = new Node(4);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(2);

	int k = 5;
	// printKPath(root, k);
    solve(root, k);

	return 0;
}
