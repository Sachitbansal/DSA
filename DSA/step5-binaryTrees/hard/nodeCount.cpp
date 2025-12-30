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

    void anss(TreeNode* root, int &ans){
        if (root) {
            ans++;
            anss(root->right, ans);
            anss(root->left, ans);
        } else return;
        
    }
    int countNodes(TreeNode* root) {
        int ans = 0;
        anss(root, ans);
        return ans;
    }
};