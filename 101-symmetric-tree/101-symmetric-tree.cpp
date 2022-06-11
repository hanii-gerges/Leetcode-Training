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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*>oldNodes;
        
        oldNodes.push_back(root);
        while (true) {
            vector<TreeNode*>newNodes;
            bool allNull = true;
            for (int i = 0; i < oldNodes.size(); i++) {
                if (oldNodes[i] == NULL) {
                    newNodes.push_back(NULL);
                    newNodes.push_back(NULL);
                }
                else {
                    newNodes.push_back(oldNodes[i]->left);
                    newNodes.push_back(oldNodes[i]->right);
                }
            }

            bool isPalindrome = true;
            for (int i = 0; i < newNodes.size(); i++) {
                if (newNodes[i] != NULL) allNull = false;
                
                if (newNodes[i] == NULL && newNodes[newNodes.size() - i - 1] == NULL) continue;
                else if (newNodes[i] == NULL || newNodes[newNodes.size() - i - 1] == NULL) return false;
                else if (newNodes[i]->val != newNodes[newNodes.size() - i - 1]->val) isPalindrome = false;
            }

            if (allNull) break;
            if (!isPalindrome) {
                return false;
            }
            
            oldNodes.assign(newNodes.begin(), newNodes.end());
        }
        return true;
    }
};