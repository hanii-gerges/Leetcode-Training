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
    TreeNode* invertTree(TreeNode* root) {
      if (!root) {
        return NULL;
      }
      if (!root->left && !root->right) {
        return root;
      }
      TreeNode* left;
      TreeNode* right;
      if (root->left && !root->right) {
        left = invertTree(root->left);
        root->right = left;
        root->left = NULL;
      }
      else if (root->right && !root->left) {
        right = invertTree(root->right);
        root->left = right;
        root->right = NULL;
      }
      else if (root->right && root->left) {
        left = invertTree(root->left);
        right = invertTree(root->right);
        root->left = right;
        root->right = left;
      }
      
      return root;
    }
};