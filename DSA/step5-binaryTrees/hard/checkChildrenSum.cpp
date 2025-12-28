/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
  
  
    bool isSumProperty(Node *root) {
        // code here
        if (!root) return true;
        if (!root->left && !root->right) return true;
        int leftVal = root->left ? root->left->data : 0;
        int rightVal = root->right ? root->right->data : 0;

        if (root->data == leftVal + rightVal) {
            return isSumProperty(root->right) && isSumProperty(root->left);
        }
        return false;
    
        
    }
};
