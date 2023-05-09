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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // method: BFS
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            int s = q.size();
            vector<int> level;
            for (int i = 0; i < s; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            result.insert(result.begin(), level);
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // method: DFS
        vector<vector<int>> ans;
        dfs(root, ans, 0);
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<vector<int>>& ans, int depth) {
        if (!root) return;
        while (ans.size() < depth + 1) ans.push_back({});

        if (depth % 2 == 0) {
            ans[depth].push_back(root->val);
        }
        else {
            ans[depth].insert(ans[depth].begin(), root->val);
        }
        dfs(root->left, ans, depth + 1);
        dfs(root->right, ans, depth + 1);
    }
};