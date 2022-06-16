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
    int mx = 0;
    void dfs(TreeNode* node, int depth) {
        if(node == NULL) return;
        mx = max(mx, depth);
        if (node->left != NULL) dfs(node->left, depth+1);
        if (node->right != NULL) dfs(node->right, depth+1);
        
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return mx;
    }
};