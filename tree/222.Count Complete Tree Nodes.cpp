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
    int countNodes(TreeNode* root) {
        // method 1: DFS
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    // time complexity: O(n)
    // space complexity: O(h)
};


class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftLevel = leftDepth(root);
        int rightLevel = rightDepth(root);
        if (leftLevel == rightLevel) {
            // 2^0 + 2^1 + 2^2 + ... + 2^n = 2^n - 1
            return (1 << leftLevel) - 1; 
        }
        else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
        
    }
private:
    int leftDepth(TreeNode* root) {
        int depth = 0;
        while (root) {
            depth += 1;
            root = root->left;
        }
        return depth;
    }

    int rightDepth(TreeNode* root) {
        int depth = 0;
        while (root) {
            depth += 1;
            root = root->right;
        }
        return depth;
    }
};