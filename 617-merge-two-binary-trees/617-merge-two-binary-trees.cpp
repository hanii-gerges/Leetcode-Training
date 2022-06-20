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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        int value = 0;
        if (!root1 && !root2) return NULL;
        if (!root1 && root2) value = root2->val;
        if (root1 && !root2) value = root1->val;
        if (root1 && root2) value = root1->val + root2->val;

        TreeNode *mergeLeft = mergeTrees(root1?root1->left:NULL, root2?root2->left:NULL);
        TreeNode *mergeRight = mergeTrees(root1?root1->right:NULL, root2?root2->right:NULL);
        TreeNode *node = new TreeNode(value, mergeLeft, mergeRight);
        return node;
    }
};