#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char d) {
        data = d;
        left = right = NULL;
    }
};

void preOrder(TreeNode* root) {
    if(!root)   return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// TreeNode* create(string str, int idx, int n) {
//     if(idx == n)    return NULL;
//     if(str[idx] == '(') return create(str,idx+1,n);

//     TreeNode* node = new TreeNode(str[idx]);
//     create(str,idx+1,n);
// }

TreeNode* createTree(string str) {
    stack<TreeNode*> st;
    TreeNode* root = NULL;

    for(int i=0;i<str.size();i++) {
        cout<<"idx:"<<i<<"\n";
        if((str[i] >= '0' && str[i] <= '9') || str[i] == '(') {
            cout<<"Node created:"<<str[i]<<"\n";
            st.push(new TreeNode(str[i]));
            if(st.size() == 1) root = st.top();
        } else {
            TreeNode* curr = st.top();
            cout<<"Popped:"<<st.top()->data<<"\n";
            st.pop();
            cout<<"Popped:"<<st.top()->data<<"\n";
            st.pop();

            if(!st.empty()) {
                cout<<"Top:"<<st.top()->data<<"\n";
                if(!st.top()->left) st.top()->left = curr;
                else st.top()->right = curr;
            }
        }
    }

    cout<<"Tree created\n";

    return root;
}

int main() {
    string str = "4(2(3)(1))(6(5))";
    TreeNode* root = createTree(str);
    if(root)cout<<root->data<<"\n";
    else cout<<"No root\n";

    preOrder(root);
    return 0;
}