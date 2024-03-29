// C++ implementation of the approach
#include <iostream>
using namespace std;

// A binary tree node has data, pointer to
// left child and a pointer to right child
typedef struct treenode {
	int val;
	struct treenode* left;
	struct treenode* right;
} node;

// Helper function that allocates a new node with the
// given data and NULL left and right pointers
node* createNode(int val)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// Helper function to print Inorder traversal
void inorder(node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout <<" "<< root->val;
	inorder(root->right);
}

// mirrorify function takes two trees,
// original tree and a mirror tree
// It recurses on both the trees,
// but when original tree recurses on left,
// mirror tree recurses on right and
// vice-versa
void mirrorify(node* root, node** mirror)
{
	if (root == NULL) {
		mirror = NULL;
		return;
	}

	// Create new mirror node from original tree node
	*mirror = createNode(root->val);
	mirrorify(root->left, &((*mirror)->right));
	mirrorify(root->right, &((*mirror)->left));
}

void mirrorify2(node* root, node** mirror) {
    if(!root)   return;

    *mirror = createNode(root->val);

    if(root->left)  mirrorify2(root->left, &(*mirror)->right);
    if(root->right)  mirrorify2(root->right, &(*mirror)->left);
}

void mirrorify3(node* root) {
    if(!root)   return;

    mirrorify3(root->left);
    mirrorify3(root->right);

    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void mirrorify4(node* root) {
	if(!root)	return;

	mirrorify4(root->left);
	mirrorify4(root->right);

	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void createNewTree(node* root, node** mRoot) {
	if(!root)	return;

	*mRoot = createNode(root->val);
	createNewTree(root->left, &((*mRoot)->right));
	createNewTree(root->right, &((*mRoot)->left));
}

// Driver code
int main()
{

	node* tree = createNode(5);
	tree->left = createNode(3);
	tree->right = createNode(6);
	tree->left->left = createNode(2);
	tree->left->right = createNode(4);

	// Print inorder traversal of the input tree
	cout <<"Inorder of original tree: ";
	inorder(tree);
	node* mirror = NULL;
	// mirrorify2(tree, &mirror);
    // mirrorify3(tree);
	// mirrorify4(tree);
	createNewTree(tree, &mirror);

	// Print inorder traversal of the mirror tree
	cout <<"\nInorder of mirror tree: ";
	inorder(mirror);

	return 0;
}

// This code is contributed by shivanisinghss2110
