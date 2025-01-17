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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // method: DFS
        if (!root) return false;
        targetSum -= root->val;
        if (targetSum == 0 && !root->left && !root->right) return true;
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
    // time complexity: O(h)
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // method 2: BFS
        if (!root) return false;
        queue<pair<TreeNode*, int>> q;
        q.push({root, targetSum});
        while (!q.empty()) {
            TreeNode* tmp = q.front().first;
            int remain = q.front().second;
            q.pop();

            if (!tmp->left && !tmp->right && tmp->val == remain) return true;
            if (tmp->left) q.push({tmp->left, remain - tmp->val});
            if (tmp->right) q.push({tmp->right, remain - tmp->val});
        }
        return false;
    }
};