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


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // method 2: DFS
        map<int, vector<pair<int, int>>> mp;  // < column, < depth, value >>
        dfs(root, 0, 0, mp);

        auto cmp = [](pair<int, int> a, pair<int, int> b) { return (a.first < b.first); };

        vector<vector<int>> res;
        for (pair<int, vector<pair<int, int>>> p : mp) {
            vector<int> col;
            sort(p.second.begin(), p.second.end(), cmp);
            for (pair<int, int> n : p.second) {
                col.push_back(n.second);
            }
            res.push_back(col);
        }
        return res;
    }
private:
    void dfs(TreeNode* root, int x, int y, map<int, vector<pair<int, int>>>& mp) {
        if (!root) return;
        mp[x].push_back({y, root->val});
        dfs(root->left, x - 1, y + 1, mp);
        dfs(root->right, x + 1, y + 1, mp);
    }
};