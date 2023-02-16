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
        // method: DFS (recursive)
        // 1. check root node is null or not, if yes, return null
        // 2. check root is p or q, if yes, return itself
        // 3. DFS left and right child
        // 4. if both left and right not null, return their parent, other return the one is not null
        if (!root) return nullptr; 
        if (root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (l && r) return root;
        else if (l) return l;
        else if (r) return r;
        else return nullptr;
    }
    // time complexity: O(n)
    // space complexity: O(h)
};