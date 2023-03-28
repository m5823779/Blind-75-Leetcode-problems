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
    // method: inorder traversal (sorted)
    // for binary search tree. it inorder traversal satisfy sorted property
    // 1. create vector to store inorder traversal elements, then select (k - 1)th element
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return vec[k - 1];
    }
private:
    vector<int> vec;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vec.push_back(root->val);
        return inorder(root->right);
    }
    // time complexity: O(n)
    // space complexity: O(h)
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // method: BFS
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode* tmp = s.top();
                s.pop();
                k--;
                if (k == 0) {
                    return tmp->val;
                }
                cur = tmp->right;
            }
        }
        return INT_MIN;
    }
    // time complexity: O(k)
    // space complexity: O(k)
};