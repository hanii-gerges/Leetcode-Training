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
    int mn = 100000;
    void helper(TreeNode* node,int lvl) {
        if (!node) return;
        if (!node->left && !node->right) {
            mn = min(mn, lvl);
        }
        helper(node->left, lvl+1);
        helper(node->right, lvl+1);
        
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        helper(root, 0);
        return mn+1;
    }
};