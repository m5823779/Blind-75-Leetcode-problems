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
    void flatten(TreeNode* root) {
        // method 1: DFS (Recursion)
        returnTail(root);
    }
private:
    TreeNode* returnTail(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* leftTail = returnTail(root->left);
        TreeNode* rightTail = returnTail(root->right);
        if (leftTail) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        if (rightTail) return rightTail;
        else if (leftTail) return leftTail;
        else return root;
    }
};


class Solution {
public:
    void flatten(TreeNode* root) {
        // method 2: iterative
        stack<TreeNode*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
            if (!s.empty()) {
                cur->right = s.top();
                cur->left = nullptr;
            }
        }
    }
};