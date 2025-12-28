#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// ----------- RANDOM TREE BUILDER -----------
Node* buildRandomTree() {
    /*
            1
          /   \
         2     3
        / \     \
       4   5     6
            \
             7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);
    root->left->right->right = new Node(7);

    return root;
}

// ----------- YOUR TASK HERE -----------
void allTraversals(Node* root,
                   vector<int>& preorder,
                   vector<int>& inorder,
                   vector<int>& postorder) {

    // 👉 WRITE YOUR ONE-TRAVERSAL LOGIC HERE
    stack<pair<Node*,int>> st; // here int means num
    if (!root) return;
    st.push({root, 1});
    while(!st.empty()) {
        auto p = st.top();
        Node* node = p.first;
        int num = p.second;
        if(num == 1) {
            preorder.push_back(node->data);
            st.top().second += 1;
            if (node->left) {
                st.push({node->left, 1});
            } 
        } else if (num==2){
            inorder.push_back(node->data);
            st.top().second+=1;
            if (node->right) {
                st.push({node->right, 1});
            }
        } else if (num==3){
            postorder.push_back(node->data);
            st.pop();
        }

    }

}

// ----------- DRIVER CODE -----------
int main() {
    Node* root = buildRandomTree();

    vector<int> preorder, inorder, postorder;

    allTraversals(root, preorder, inorder, postorder);

    cout << "Preorder: ";
    for (int x : preorder) cout << x << " ";
    cout << "\n";

    cout << "Inorder: ";
    for (int x : inorder) cout << x << " ";
    cout << "\n";

    cout << "Postorder: ";
    for (int x : postorder) cout << x << " ";
    cout << "\n";

    return 0;
}
