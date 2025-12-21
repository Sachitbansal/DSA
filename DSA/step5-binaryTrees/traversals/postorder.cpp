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

vector<int> postOrder(Node* root, vector<int>& arr) {
    if (root == NULL) {
        return arr;
    }

    postOrder(root->left, arr);
    postOrder(root->right, arr);
    arr.push_back(root->data);
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
    postOrder(root, arr);

    cout << "final traversal ";
    // cout << arr.size();
    for (int i: arr){
        cout << i;
    }

   
    return 0;
}
