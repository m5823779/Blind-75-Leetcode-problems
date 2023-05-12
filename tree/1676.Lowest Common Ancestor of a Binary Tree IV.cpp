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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        set<TreeNode*> s(nodes.begin(), nodes.end());
        return solve(root, s);
    }
private:
    TreeNode* solve(TreeNode* root, set<TreeNode*>& s) {
        if (!root) return nullptr;
        if (s.find(root) != s.end()) {
            return root;
        }
        TreeNode* l = solve(root->left, s);
        TreeNode* r = solve(root->right, s);
        if (l && r) return root;
        if (l) return l;
        if (r) return r;
        return nullptr;
    }
};