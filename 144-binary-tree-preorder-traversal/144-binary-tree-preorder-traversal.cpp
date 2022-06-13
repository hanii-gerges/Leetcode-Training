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
    void helper(TreeNode* node, vector<int> &ans) {
        ans.push_back(node->val);
        if (node->left != NULL) helper(node->left, ans);
        if (node->right != NULL) helper(node->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if (root != NULL) helper(root, ans);
        
        return ans;
    }
};