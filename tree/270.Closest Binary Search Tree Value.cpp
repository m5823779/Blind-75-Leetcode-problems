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
    int closestValue(TreeNode* root, double target) {
        TreeNode* closest = root;
        while (root) {
            double diff = abs(target - (double)root->val);
            double pre_diff = abs(target - (double)closest->val);
            if (diff < pre_diff || (diff == pre_diff && root->val < closest->val)) {
                closest = root;
            }
            if (root->val > target) root = root->left;
            else if (root->val < target) root = root->right;
            else return root->val;
        }
        return closest->val;
    }
};


class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        // method 2: recursive
        int closest = root->val;
        dfs(root, target, closest);
        return closest;
    }
private:
    void dfs(TreeNode* root, double target, int& ans) {
        if (!root) return;
        if (abs(target - root->val) < abs(target - ans)) {
            ans = root->val;
        }
        if (target > root->val) dfs(root->right, target, ans);
        else dfs(root->left, target, ans);
    }
};