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
    int goodNodes(TreeNode* root) {
        // method 1: DFS
        dfs(root, INT_MIN);
        return ans;
    }
private:
    int ans = 0;
    void dfs(TreeNode* root, int maxVal) {
        if (!root) return;
        if (root->val >= maxVal) {
            ans += 1;
            maxVal = root->val;
        }
        dfs(root->left, maxVal);
        dfs(root->right, maxVal);
    }
    // time complexity: O(n)
    // space complexity: O(h)
};



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
    int goodNodes(TreeNode* root) {
        // method 2: BFS
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({ root, INT_MIN });
        while (!q.empty()) {
            TreeNode* tmp = q.front().first;
            int maxVal = q.front().second;
            q.pop();

            if (tmp->val >= maxVal) {
                ans += 1;
                maxVal = tmp->val;
            }

            if (tmp->left) q.push({ tmp->left, maxVal });
            if (tmp->right) q.push({ tmp->right, maxVal });
        }
        return ans;
    }
};