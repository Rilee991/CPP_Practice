// C++ program to find largest subtree
// sum in a given binary tree.
#include <iostream>
#include <climits>
using namespace std;

// Structure of a tree node.
struct Node {
	int key;
	Node *left, *right;
};

// Function to create new tree node.
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// Helper function to find largest
// subtree sum recursively.
int findLargestSubtreeSumUtil(Node* root, int& ans)
{
	// If current node is null then
	// return 0 to parent node.
	if (root == NULL)	 
		return 0;
	
	// Subtree sum rooted at current node.
	int currSum = root->key + 
	findLargestSubtreeSumUtil(root->left, ans)
	+ findLargestSubtreeSumUtil(root->right, ans);

	// Update answer if current subtree
	// sum is greater than answer so far.
	ans = max(ans, currSum);

	// Return current subtree sum to
	// its parent node.
	return currSum;
}

// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
	// If tree does not exist, 
	// then answer is 0.
	if (root == NULL)	 
		return 0;
	
	// Variable to store maximum subtree sum.
	int ans = INT_MIN;

	// Call to recursive function to
	// find maximum subtree sum.
	findLargestSubtreeSumUtil(root, ans);

	return ans;
}

pair<int,int> solve(Node* root) {
    if(!root)   return {0,0};

    if(root->left == root->right)   return { root->key, root->key };

    auto lst = solve(root->left);
    auto rst = solve(root->right);

    int treeSum = lst.first+rst.first+root->key;
    int res = max(treeSum, max(lst.second, rst.second));

    return { treeSum, res };
}

// Driver function
int main()
{
	/*
			1
			/ \
			/	 \
		-2	 3
		/ \	 / \
		/ \ / \
		4	 5 -6	 2
	*/

	Node* root = newNode(-1);
	root->left = newNode(21);
	root->right = newNode(-3);
	root->left->left = newNode(-4);
	root->left->right = newNode(-5);
	root->right->left = newNode(-6);
	root->right->right = newNode(-2);

	cout << findLargestSubtreeSum(root)<<endl;
	cout << solve(root).second;
	return 0;
}
