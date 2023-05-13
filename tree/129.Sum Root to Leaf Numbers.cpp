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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        long long sum = 0;

        dfs(root, ans, sum);
        return ans;
    }
private:
    void dfs(TreeNode* root, int& ans, long long sum) {
        if (!root) return;
        if (!root->left && !root->right) {
            sum = sum * 10 + root->val;
            ans += sum;
        }
        sum = sum * 10 + root->val;
        dfs(root->left, ans, sum);
        dfs(root->right, ans, sum);
    }
};