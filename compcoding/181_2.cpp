#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TreeNode* root) {
    if(!root)   return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

TreeNode* createTree(string str, int& i, int j) {
    TreeNode *root = NULL;

    while(i<=j) {
        // cout<<str[i]<<" ";
        if(str[i] >= '0' && str[i] <= '9') {
            int num = 0;
            while(str[i] >= '0' && str[i] <= '9') {
                num = num*10 + (str[i]-'0');
                i++;
            }
            // cout<<"val:"<<num<<"\n";
            root = new TreeNode(num);
        } else if(str[i] == '(') {
            i++;
            if(!root->left) root->left = createTree(str, i, j);
            else root->right = createTree(str, i, j);
        } else {
            i++;
            break;
        }
    }

    return root;
}

int main() {
    string str = "4(2(3)(1))(6(5))";

    int start = 0;
    TreeNode* root = createTree(str, start, str.size()-1);

    preOrder(root);

    return 0;
}