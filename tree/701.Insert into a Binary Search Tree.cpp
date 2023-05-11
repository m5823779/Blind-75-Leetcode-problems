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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // method 1: recursive
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        if (val > root->val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        return root;
    }
};


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // method 2: itervative
        TreeNode* cur = root;
        TreeNode* pre;
        TreeNode* new_node = new TreeNode(val);
        if (!cur) {
            cur = new_node;
            return cur;
        }

        while (cur) {
            pre = cur;
            if (val < cur->val) cur = cur->left;
            else cur = cur->right;
        }

        if (val < pre->val) pre->left = new_node;
        else pre->right = new_node;
        return root;
    }
};