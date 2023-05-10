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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // method: recursive
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return construct(postorder, mp, postorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode* construct(vector<int>& postorder, unordered_map<int, int>& mp, int root_id, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        int val = postorder[root_id];
        int m = mp[val];
        TreeNode* root = new TreeNode(val);
        root->left = construct(postorder, mp, root_id - inEnd + m - 1, inStart, m - 1);
        root->right = construct(postorder, mp, root_id - 1, m + 1, inEnd);
        return root;
    }
};