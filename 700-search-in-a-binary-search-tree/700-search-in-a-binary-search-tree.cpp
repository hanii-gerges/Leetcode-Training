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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = nullptr;
        if (!root) return NULL;
        if (root->val == val) {
            return root;
        }
        if (val < root->val) {
            node = searchBST(root->left ? root->left : NULL, val);
        }
        
        if (val > root->val) {
            node = searchBST(root->right ? root->right : NULL, val);
        }
        
        return node;
    }
};