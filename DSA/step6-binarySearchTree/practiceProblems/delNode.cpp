/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void attacher(TreeNode* root, TreeNode* node){
        if (!root) return;
        if (node->val > root->val){
            if (!root->right){
                root->right = node;
                return;
            }
            attacher(root->right, node);
        } else {
            if (!root->left){
                root->left = node;
                return;
            }
            attacher(root->left, node);
        };
    }
    void act(TreeNode* root, int key){
        if (!root) return;
        if (root->left && root->left->val == key) {
            if (root->left->left) {
                if (root->left->right) attacher(root->left->left, root->left->right);
                root->left = root->left->left;
            } else if (root->left->right){
                root->left = root->left->right;
            } else {
                root->left = NULL;
            }
            return;
        } else if (root->right && root->right->val == key) {
            if (root->right->right) {
                if (root->right->left) attacher(root->right->right, root->right->left);
                root->right = root->right->right;
            } else if (root->right->left){
                root->right = root->right->left;
            } else {
                root->right = NULL;
            }
            return;
        } else {
            act(root->left, key);
            act(root->right, key);
        }
        return;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root && root->val == key) {
            if (!root->right && !root->left) return NULL;
            if (!root->right) return root->left;
            if (!root->left) return root->right;
            if (root->left && root->right){
                attacher(root->right, root->left);
                return root->right;
            }
        }
        act(root, key);
    
        return root;
    }
};