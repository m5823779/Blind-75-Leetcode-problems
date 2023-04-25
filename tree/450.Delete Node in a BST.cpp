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