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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // method: BFS
        // number of column, { depth, node's value }
        map<int, vector<pair<int, int>>> mp; 

        // TreeNode, number of column
        queue<pair<TreeNode*, int>> q;
        
        int depth = 0;
        if (root) q.push({root, 0});
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front().first;
                int col = q.front().second;
                q.pop();

                mp[col].push_back({depth, node->val});
                if (node->left) q.push({node->left, col - 1});
                if (node->right) q.push({node->right, col + 1});
            }
            depth++;
        }

        auto cmp = [](auto a, auto b){
            if (a.first == b.first) return a.second < b.second;
            else return a.first < b.first;
        };

        vector<vector<int>> ans;
        for (auto p : mp) {
            sort(p.second.begin(), p.second.end(), cmp);
            vector<int> tmp;
            for (pair<int, int> n : p.second) {
                tmp.push_back(n.second);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};