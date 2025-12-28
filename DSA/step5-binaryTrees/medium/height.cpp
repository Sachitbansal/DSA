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

int maxDepth(Node* root) {

    if (root==NULL) return 0;
      
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
    
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

    int ans = maxDepth(root);

    cout << "Max Depth ";
    cout << ans;
   
    return 0;
}
