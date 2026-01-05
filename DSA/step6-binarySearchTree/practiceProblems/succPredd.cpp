/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void pre(Node* root, int key, Node* &pred) {
        if (!root) return;
        if (root->data < key) {
            if (pred && root->data > pred->data) {
                    pred = root;
            } else if (!pred) pred = root;
            
            pre(root->right, key, pred);
        } else pre(root->left, key, pred);
        
    }
    void suc(Node* root, int key, Node* &succ) {
        if (!root) return;
        if (root->data > key) {
            if (succ && root->data < succ->data) {
                    succ = root;
            } else if (!succ) succ = root;
            suc(root->left, key, succ);
        } else suc(root->right, key, succ);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pred = NULL;
        Node* succ = NULL;
        pre(root, key, pred);
        suc(root, key, succ);
        return {pred, succ};
        
    }
};