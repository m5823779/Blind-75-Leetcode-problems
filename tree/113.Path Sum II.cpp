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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;    
    }
private:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (!root) return;
        if (!root->left && !root->right && root->val == targetSum) {
            if (root->val == targetSum) {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }

        path.push_back(root->val);
        dfs(root->left, targetSum - root->val, path);
        dfs(root->right, targetSum - root->val, path);
        path.pop_back();
    }
};