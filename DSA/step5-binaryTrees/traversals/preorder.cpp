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

vector<int> preOrder(Node* root, vector<int>& arr) {
    if (root == NULL) {
        return arr;
    }

    arr.push_back(root->data);
    preOrder(root->left, arr);
    preOrder(root->right, arr);

    return arr;
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

    vector<int> arr;
    preOrder(root, arr);

    cout << "final traversal ";
    // cout << arr.size();
    for (int i: arr){
        cout << i;
    }

   
    return 0;
}
