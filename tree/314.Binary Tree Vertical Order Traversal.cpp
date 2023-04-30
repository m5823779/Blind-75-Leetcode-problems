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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // method: BFS
        if (!root) return {};
        map<int, vector<int>> mp;  // <number of col, value>
        queue<pair<TreeNode*, int>> q;  // <TreeNode, number of col>
        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int col = q.front().second;
            q.pop();

            mp[col].push_back(node->val);
            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }

        vector<vector<int>> ans;
        for (auto p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};