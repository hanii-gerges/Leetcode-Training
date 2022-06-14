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
    vector<vector<int>> bfs (TreeNode* node) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>>q;
        if (node != NULL) {
            q.push({node, 0});
        }
        vector<int>temp;
        int last = 0;
        while(!q.empty()) {
            TreeNode* current = q.front().first;
            int level = q.front().second;
            if (last != level) {
                ans.push_back(temp);
                temp.clear();
            }

            if (current != NULL) {
                temp.push_back(current->val);
                q.push({current->left, level+1});
                q.push({current->right, level+1});
            }
            last = level;
            q.pop();
        }
        
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
};