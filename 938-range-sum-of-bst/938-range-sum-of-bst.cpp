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
    int rangeSumBST(TreeNode* root, int low, int high) {
      if (!root) {
        return 0;
      }
    
      int left = 0, right = 0;

      if (root->val > low) {
        left = rangeSumBST(root->left, low, high);
      }

      if (root->val < high) {
        right = rangeSumBST(root->right, low, high);
      }

      int val = root->val >= low && root->val <= high ? root->val : 0;
      return left + right + val;
    }
};