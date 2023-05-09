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
    vector<int> postorderTraversal(TreeNode* root) {
        // method: iterative approach
        vector<int> ans;
        stack<TreeNode*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            if (!tmp->left && !tmp->right) {
                s.pop();
                ans.push_back(tmp->val);
            }

            if (tmp->right) {
                s.push(tmp->right);
                tmp->right = nullptr;
            }
            if (tmp->left) {
                s.push(tmp->left);
                tmp->left = nullptr;
            }
        }
        return ans;
    }
};