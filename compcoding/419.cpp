#include <iostream>
#include <unordered_map>
using namespace std; 

// A utility function to find 
// max of two integers 
int max(int x, int y) 
{ 
	return (x > y) ? x : y; 
} 

/* A binary tree node has data, 
pointer to left child and a 
pointer to right child */
class node 
{ 
	public:
	int data; 
	node *left, *right; 
}; 

// The function returns size of the 
// largest independent set in a given 
// binary tree 
int LISS(node *root) 
{ 
	if (root == NULL) 
	return 0; 

	// Calculate size excluding the current node 
	int size_excl = LISS(root->left) + 
					LISS(root->right); 

	// Calculate size including the current node 
	int size_incl = 1; 
	if (root->left) 
		size_incl += LISS(root->left->left) +
					LISS(root->left->right); 
	if (root->right) 
		size_incl += LISS(root->right->left) + 
					LISS(root->right->right); 

	// Return the maximum of two sizes 
	return max(size_incl, size_excl); 
} 

int solve(node *root, bool canSelect, unordered_map<node*,int> &mp) {
    if(!root)   return 0;

    if(mp[root] != 0) return mp[root];

    int w1 = canSelect ? 1 + solve(root->left, false, mp) + solve(root->right, false, mp) : 0;
    int w2 = solve(root->left, true, mp) + solve(root->right, true, mp);

    return mp[root] = max(w1,w2);
}

// A utility function to create a node 
node* newNode( int data ) 
{ 
	node* temp = new node();
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

int solve2(node* root, bool canBeTaken) {
	if(!root)	return 0;
	
	int w1 = canBeTaken ? solve2(root->left,false)+solve2(root->right,false)+1 : 0;
	int w2 = solve2(root->left,true)+solve2(root->right,true);

	return max(w1, w2);
}

int solveutil(node* root) {
	return max(solve2(root, true), solve2(root, false));
}

// Driver Code
int main() 
{ 
	// Let us construct the tree 
	// given in the above diagram 
	node *root = newNode(20); 
	root->left = newNode(8); 
	root->left->left = newNode(4); 
	root->left->right = newNode(12); 
	root->left->right->left = newNode(10); 
	root->left->right->right = newNode(14); 
	root->right = newNode(22); 
	root->right->right = newNode(25); 

	cout<<solveutil(root);

    // unordered_map<node*,int> mp;

	// cout << "Size of the Largest"
	// 	<< " Independent Set is "
	// 	<< max(solve(root,true,mp),solve(root,false,mp)); 

	return 0; 
} 
