#include <iostream>
#include <stack>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Iterative function to perform inorder traversal on the tree
void inorderIterative(Node* root)
{
    // create an empty stack
    stack<Node*> stack;
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}

void ior(Node* root) {
    if(!root)   return;

    ior(root->left);
    cout<<root->data<<" ";
    ior(root->right);
}

void ioi(Node* root) {
    if(!root)   return;

    stack<Node*> st;
    // st.push(root);
    Node* curr = root;

    while(!st.empty() || curr) {
        if(curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            Node* top = st.top();
            st.pop();
            cout<<top->data<<" ";
            curr = top->right;
        }
    }
}

void pre(Node* root) {
    if(!root)   return;

    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

void prei(Node* root) {
    stack<Node*> st;

    Node*curr = root;

    while(!st.empty() || curr) {
        if(curr) {
            cout<<curr->data<<" ";
            st.push(curr);
            curr = curr->left;
        } else {
            Node* top = st.top();
            st.pop();
            curr = top->right;
        }
    }
}

void prei2(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (!st.empty() || curr) {
        if(curr) {
            st.push(curr);
            cout<<curr->data<<" ";
            curr = curr->left;
        } else {
            Node* tp = st.top();
            st.pop();

            curr = tp->right;
        }
    }
    
}

void post(Node* root) {
    if(!root)   return;

    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}

void posti(Node* root) {
    if(!root)   return;

    stack<Node*> st;
    stack<int> res;
    st.push(root);

    while(!st.empty()) {
        Node *top = st.top();
        st.pop();

        res.push(top->data);

        if(top->left) st.push(top->left);
        if(top->right) st.push(top->right);
    }

    while (!res.empty()) {
        cout<<res.top()<<" ";
        res.pop();
    }
    
}

void prei3(Node* root) {
    // print middle, left, right
    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {
        Node* tp = st.top();
        st.pop();
        cout<<tp->data<<" ";

        if(tp->right) st.push(tp->right);
        if(tp->left) st.push(tp->left);
    }
}

void ini3(Node* root) {
    // left, middle, right
    stack<pair<Node*,bool>> st;
    st.push({ root, false });

    while(!st.empty()) {
        if(st.top().first->left) {
            if(!st.top().second) {
                st.top().second = true;
                st.push({ st.top().first->left, false });
            } else {
                cout<<st.top().first->data<<" ";
                auto tp = st.top();
                st.pop();
                if(tp.first->right) {
                    st.push({ tp.first->right, false });
                }
            }
        } else {
            cout<<st.top().first->data<<" ";
            st.pop();
        }
    }
}

void posti3(Node* root) {
    stack<pair<Node*,bool>> st;

    st.push({ root, false });

    while(!st.empty()) {
        auto tp = st.top();
        if(!tp.second && tp.first->left != tp.first->right) {
            st.top().second = true;
            if(tp.first->right) st.push({ tp.first->right, false });
            if(tp.first->left) st.push({ tp.first->left, false });
        } else {
            cout<<tp.first->data<<" ";
            st.pop();
        }
    }
}

int main()
{ //[3] 4, 2, 1
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    // inorderIterative(root);
    cout<<"Inorder:\n";
    ior(root);
    cout<<"\n";
    ini3(root);
    cout<<"\n";
    // ioi(root);
    // cout<<"\n";
    cout<<"Preorder:\n";
    pre(root);
    cout<<"\n";
    prei3(root);
    cout<<"\n";
    // prei(root);
    // cout<<"\n";
    // prei2(root);
    // cout<<"\n";
    cout<<"Postorder:\n";
    post(root);
    cout<<"\n";
    // posti(root);
    // cout<<"\n";
    posti3(root);
    cout<<"\n";
    
    return 0;
}