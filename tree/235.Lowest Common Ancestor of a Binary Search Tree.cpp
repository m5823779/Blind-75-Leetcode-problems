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
        // method 1: recursive
        // case 1. if p and q is smaller than root's value. find p and q in root's left sub-tree
        // case 2. if p and q is larger than root's value. find p and q in root's right sub-tree
        // case 3. else (means p or q equal to root's value) return root itself
        
        if (p->val < root->val && q->val < root->val) 
            return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val) 
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
    // time complexity: O(n)
    // space complexity: O(h)
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // method 2: iterative
        // case 1. if p and q is smaller than root's value. find p and q in root's left sub-tree
        // case 2. if p and q is larger than root's value. find p and q in root's right sub-tree
        // case 3. else (means p or q equal to root's value) return root itself

        while (root) {
            if (p->val < root->val && q->val < root->val) 
                root = root->left;
            else if (p->val > root->val && q->val > root->val) 
                root = root->right;
            else 
                return root;
        }
        return root;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};