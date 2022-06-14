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
        queue<TreeNode*>q;
        if (node != NULL) {
            q.push(node);
        }
        while(!q.empty()) {
            vector<int>temp;
            int s = q.size();
            while(s--) {
                TreeNode* current = q.front();
                q.pop();
                temp.push_back(current->val);
                if (current->left)q.push(current->left);
                if (current->right)q.push(current->right);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
};