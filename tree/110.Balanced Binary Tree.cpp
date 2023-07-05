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
    bool isBalanced(TreeNode* root) {
        // method: DFS
        if (!root) return true;
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        if (abs(lDepth - rDepth) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    // time complexity: O(n) + O(n/2) + ... = O(nlogn)
    // space complexiy: O(h)
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // method 2: DFS (optimize)
        if (!root) return true;
        bool balance = true;
        solve(root, balance);
        return balance;
    }

    int solve(TreeNode* root, bool& balance) {
        if (!root) return 0;
        int lDepth = solve(root->left, balance);
        int rDepth = solve(root->right, balance);

        if (abs(lDepth - rDepth) > 1) {
            balance = false;
            return -1;
        }
        return 1 + max(lDepth, rDepth);
    }
    // time complexity: O(n)
    // space compliexty: O(h)
};