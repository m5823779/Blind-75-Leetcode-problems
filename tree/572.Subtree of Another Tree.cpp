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
    // method: recursive
    // 1. define a function to check two tree are same or not
    // 2. if sub-tree is null return true
    // 3. if tree is null return false
    // 4. check tree and sub-tree are same or not
    // 5. check tree's left child and sub-tree are same or not / check tree's right child and sub-tree are same or not
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        if (sameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
            
private:
    bool sameTree(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;
        if (r1->val != r2->val) return false;
        return sameTree(r1->left, r2->left) && sameTree(r1->right, r2->right);
    }
    // time complexity: O(ST) which S is the number of nodes for tree, and T is the number of nodes for sub-tree
    // space complexity: O(h) maximum depth of binary tree
};