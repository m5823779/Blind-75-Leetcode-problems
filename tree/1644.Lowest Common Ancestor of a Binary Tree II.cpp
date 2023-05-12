/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = postorder(root, p, q);
        return count == 2 ? lca : nullptr;
    }

private:
    int count = 0;
    TreeNode* postorder(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        TreeNode* l = postorder(root->left, p, q);
        TreeNode* r = postorder(root->right, p, q);
        if (root == p || root == q) {
            count++;
            return root;
        }

        if (l && r) return root;
        if (l) return l;
        if (r) return r;
        return nullptr;
    }
};