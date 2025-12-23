#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node (int val){
        data = val;
        left = right = NULL;
    }
};

vector<int> IterativePreorder(Node* root) {

    vector<int> ans;

    if (root == NULL) return ans;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if (root->right!=NULL) st.push(root->right);
        if (root->left!=NULL) st.push(root->left);
    }

    return ans;
    
}

int main() {
    
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<int> ans = IterativePreorder(root);

    cout << "final traversal ";
    // cout << arr.size();
    for (auto i: ans){
            cout << i;
    }

   
    return 0;
}
