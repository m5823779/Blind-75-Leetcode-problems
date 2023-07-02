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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // method 1: Recrusive
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left) {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            else if (!root->right) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            else {
                TreeNode* min_node = root->right;
                while (min_node->left) {
                    min_node = min_node->left;
                }
                root->val = min_node->val;
                root->right = deleteNode(root->right, min_node->val);
                return root;
            }
        }
        return root;
    }
};



class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // method 2: Iterative
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur) {
            if (key == cur->val) break;

            pre = cur;
            if (key > cur->val) cur = cur->right;
            else cur = cur->left;
        }

        // target node not exist in tree
        if (!cur) return root;
        // now current node need to delete
        // first root node is the target node
        if (!pre) return solve(cur);
        if (key > pre->val) pre->right = solve(cur);
        if (key < pre->val) pre->left = solve(cur);
        return root;
    }

    TreeNode* solve(TreeNode* root) {
        if (!root->left && !root->right) return nullptr;
        else if (!root->left) {
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (!root->right) {
            TreeNode* tmp = root->left;
            delete root;
            return tmp;
        }
        else {
            TreeNode* rightMin = root->right;
            while (rightMin->left) rightMin = rightMin->left;
            root->val = rightMin->val;
            root->right = deleteNode(root->right, rightMin->val);
            return root;
        }
    }
};