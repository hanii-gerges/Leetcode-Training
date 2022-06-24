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
    void getFreq(TreeNode* root) {
        if (!root) return;
        mp[root->val] = 1;
        getFreq(root->left);
        getFreq(root->right);
    }
    bool helper(TreeNode* root, int val) {
        if (!root) return 0;
        if (mp[val-root->val] && root->val != val - root->val)return 1;
        bool searchLeft = helper(root->left, val);
        bool searchRight = helper(root->right, val);
        
        return max(searchLeft, searchRight);
    }
    bool findTarget(TreeNode* root, int k) {
        getFreq(root);
        return helper(root, k);
    }
};