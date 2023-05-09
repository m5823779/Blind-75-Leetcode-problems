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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // method 1: BFS
        if (!root) return {};
        vector<vector<int>> result;
        int depth = 0;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> level;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* tmp = q.front();
                q.pop();

                if (depth % 2 == 0) {
                    level.push_back(tmp->val);
                }
                else {
                    level.insert(level.begin(), tmp->val);
                }

                if (tmp->left) q.push(tmp->left);  
                if (tmp->right) q.push(tmp->right);
            }
            result.push_back(level);
            depth++;
        }
        return result;
    }
    // time complexity: O(n)
    // space complexity: O(n / 2) -> O(n)
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