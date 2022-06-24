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
    map<int,bool>mp;
    bool findTarget(TreeNode* root, int k) {
        if (!root) return 0;
        if (mp[k - root->val] && root->val != k - root->val) {
            return true;
        }
        mp[root->val] = true;
        
        return max(findTarget(root->left, k), findTarget(root->right, k));
    }
};