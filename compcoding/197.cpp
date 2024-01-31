/* C++ program to calculate Kth ancestor of given node */
#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// temporary node to keep track of Node returned
// from previous recursive call during backtrack
Node* temp = NULL;

// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node , int &k)
{ 
	// Base case
	if (!root)
		return NULL;
	
	if (root->data == node||
	(temp = kthAncestorDFS(root->left,node,k)) ||
	(temp = kthAncestorDFS(root->right,node,k)))
	{ 
		if (k > 0)	 
			k--;
		
		else if (k == 0)
		{
			// print the kth ancestor
			cout<<"Kth ancestor is: "<<root->data;
			
			// return NULL to stop further backtracking
			return NULL;
		}
		
		// return current node to previous call
		return root;
	}
} 

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

pair<int,int> findkthAncestor(Node* root, int node, int k) {
    if(!root)    return { -1, -1 };
    cout<<root->data<<" ";

    if(root->data == node) {
        cout<<"Node found\n";
        return { 0, root->data };
    }

    auto lst = findkthAncestor(root->left, node, k);
    auto rst = findkthAncestor(root->right, node, k);

    cout<<"(lst):"<<lst.first<<" "<<lst.second<<"\n";
    cout<<"(rst):"<<rst.first<<" "<<rst.second<<"\n";

    if(lst.first == rst.first)  return { -1, -1 };
    if(lst.first != -1) return { lst.first + 1 < k ? lst.first+1 : k, lst.first + 1 <= k ? root->data : lst.second };
    return { rst.first + 1 < k ? rst.first+1 : k, rst.first + 1 <= k ? root->data : rst.second };
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	int k = 3;
	int node = 5;

	// print kth ancestor of given node
	// Node* parent = kthAncestorDFS(root,node,k);
	
	// check if parent is not NULL, it means
	// there is no Kth ancestor of the node
	// if (parent)
	// 	cout << "-1";
    auto ans = findkthAncestor(root, node, k);
    cout<<(ans.first == k ? ans.second : -1);
	
	return 0;
}
