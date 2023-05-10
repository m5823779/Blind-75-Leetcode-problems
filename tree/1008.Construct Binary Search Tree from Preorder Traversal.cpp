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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, INT_MIN, INT_MAX);
    }

private:
    int id = 0;
    TreeNode* construct(vector<int>& preorder, int minBound, int maxBound) {
        if (id >= preorder.size()) return nullptr;
        int val = preorder[id];
        if (val > minBound && val < maxBound) {
            id++;
            TreeNode* root = new TreeNode(val);
            root->left = construct(preorder, minBound, val);
            root->right = construct(preorder, val, maxBound);
            return root;
        }
        else {
            return nullptr;
        }
    }
};