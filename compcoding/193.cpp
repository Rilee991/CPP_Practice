// C++ program to find maximum sum from a subset of
// nodes of binary tree
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/* A binary tree node structure */
struct node {
	int data;
	struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	struct node* temp = new struct node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Declaration of methods
int sumOfGrandChildren(node* node,
					map<struct node*, int>& mp);
int getMaxSum(node* node);
int getMaxSumUtil(node* node, map<struct node*, int>& mp);

// method returns maximum sum possible from subtrees rooted
// at grandChildrens of node 'node'
int sumOfGrandChildren(node* node,
					map<struct node*, int>& mp)
{
	int sum = 0;

	// call for children of left child only if it is not
	// NULL
	if (node->left)
		sum += getMaxSumUtil(node->left->left, mp)
			+ getMaxSumUtil(node->left->right, mp);

	// call for children of right child only if it is not
	// NULL
	if (node->right)
		sum += getMaxSumUtil(node->right->left, mp)
			+ getMaxSumUtil(node->right->right, mp);

	return sum;
}

// Utility method to return maximum sum rooted at node
// 'node'
int getMaxSumUtil(node* node, map<struct node*, int>& mp)
{
	if (node == NULL)
		return 0;

	// If node is already processed then return calculated
	// value from map
	if (mp.find(node) != mp.end())
		return mp[node];

	// take current node value and call for all grand
	// children
	int incl = node->data + sumOfGrandChildren(node, mp);

	// don't take current node value and call for all
	// children
	int excl = getMaxSumUtil(node->left, mp)
			+ getMaxSumUtil(node->right, mp);

	// choose maximum from both above calls and store that
	// in map
	mp[node] = max(incl, excl);

	return mp[node];
}

// Returns maximum sum from subset of nodes
// of binary tree under given constraints
int getMaxSum(node* node)
{
	if (node == NULL)
		return 0;
	map<struct node*, int> mp;
	return getMaxSumUtil(node, mp);
}

vector<int> st;
int solve(node* root, bool canSelect, map<pair<node*,bool>,int> &mp) {
    if(!root)   return 0;
    st.push_back(1);

    if(mp.find({root, canSelect}) != mp.end())  return mp[{root, canSelect}];

    int sum1 = canSelect ? root->data + solve(root->left, false, mp) + solve(root->right, false, mp) : 0;
    int sum2 = solve(root->left, true, mp) + solve(root->right, true, mp);

    return mp[{ root, canSelect }] = max(sum1, sum2);
}

// Driver code 
int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	root->left->left = newNode(1);

	cout << getMaxSum(root) << endl;
    map<pair<node*,bool>,int> mp;
    cout << max(solve(root, true, mp), solve(root, false, mp)) << endl;
    cout<<st.size();
	return 0;
}
