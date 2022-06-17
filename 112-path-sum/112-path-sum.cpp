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
    bool helper(TreeNode* node, int targetSum, int sum) {
        if (!node) return false;
        if (!node->left && !node->right) {
            if (targetSum == sum + node->val)
                return true;
            else return false;
        }
        bool left = 0;
        bool right = 0;
        if (node->left) left = helper(node->left, targetSum, sum + node->val);
        if (node->right) right = helper(node->right, targetSum, sum + node->val);
        return max(left, right);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root, targetSum, sum);
    }
};