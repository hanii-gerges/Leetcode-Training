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
    vector<int> rightSideView(TreeNode* root) {
      queue<TreeNode*>q;
      vector<int>ans;
      if (root) {
        q.push(root);
      }
      while (!empty(q)) {
        int size = q.size();
        vector<TreeNode*>temp;
        for (int i = 0; i < size; i++) {
          TreeNode* node = q.front();
          if (node->left) {
            q.push(node->left);
          }
          if (node->right) {
            q.push(node->right);
          }
          q.pop();
          if (i == size-1) {
            ans.push_back(node->val);
          }
        }
      }
      return ans;
    }
};