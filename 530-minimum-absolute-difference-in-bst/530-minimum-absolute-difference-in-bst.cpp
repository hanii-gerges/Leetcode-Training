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
    vector<int>vec;
    void inorderTraversal(TreeNode *node) {
        if (!node) return;
        
        inorderTraversal(node->left);
        vec.push_back(node->val);
        inorderTraversal(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = 1e4;
        inorderTraversal(root);
        for (int i = 1; i < vec.size(); i++) {
            ans = min(ans, vec[i] - vec[i-1]);
        }
        return ans;
    }
};