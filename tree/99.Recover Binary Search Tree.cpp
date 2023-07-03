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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        TreeNode* pre = nullptr;
        TreeNode* cur = root;

        stack<TreeNode*> s;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode* tmp = s.top();
                s.pop();

                if (pre && tmp->val <= pre->val) {
                    if (!first) {
                        first = pre;
                        second = tmp;
                    }
                    else {
                        second = tmp;
                    }
                }
                pre = tmp;
                cur = tmp->right;
            }
        }        
        int tmp_val = first->val;
        first->val = second->val;
        second->val = tmp_val;
    }
};


class Solution {
public:
    TreeNode* pre = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    void recoverTree(TreeNode* root) {
        // method 2: DFS (inoreder)
        inorder(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (pre && root->val <= pre->val) {
            if (!first) {
                first = pre;
                second = root;
            }
            else {
                second = root;
            }
        }
        pre = root;
        inorder(root->right);
    }
};