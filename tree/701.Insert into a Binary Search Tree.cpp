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
        TreeNode* new_node = new TreeNode(val);
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while (cur) {
            pre = cur;
            if (cur->val > val) cur = cur->left;
            else if (cur->val < val) cur = cur->right;
            else return root;
        }
        if (!pre) return new_node;
        if (pre->val < val) pre->right = new_node;
        else pre->left = new_node;
        return root;
    }
};