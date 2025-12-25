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

    int check(Node* root) {
        if (root == NULL) return 0;
        int rh = check(root->right);
        int lh = check(root->left);

        if (rh==-1 || lh == -1) return -1;
        if (abs(rh-lh)>1) return -1;
        return 1 + max(lh,rh);
    }

    bool isBalanced(Node* root) {
        return  (check(root) != -1 );
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

    bool ans = isBalanced(root);

    cout << "Max Depth ";
    cout << ans;
   
    return 0;
}
