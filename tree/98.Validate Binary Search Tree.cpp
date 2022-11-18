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
    bool isValidBST(TreeNode* root) {
        // method 1: recursive clip boundary
        //                 a     (-inf, inf)
        //  (-inf, a] /        \ [a, inf)
        //           /          \
        //          b            c
        // 1. define boundary -inf & inf
        // 2. if root node is null return true
        // 3. for left node >= max boundary, return false
        // 4. for right node <= min boundary, return false
        // 5. recursive
        return fun(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool fun(TreeNode* root, long min_val, long max_val) {
        if (!root) return true;
        if (root->val >= max_val || root->val <= min_val) return false;
        return fun(root->left, min_val, root->val) && fun(root->right, root->val, max_val);
    }
    // time complexity: O(n)
    // space complexity: O(h)
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // method 1: recursive clip boundary
        //                 a     (-inf, inf)
        //  (-inf, a] /        \ [a, inf)
        //           /          \
        //          b            c
        // 1. define boundary -inf & inf
        // 2. if root node is null return true
        // 3. for left node >= max boundary, return false
        // 4. for right node <= min boundary, return false
        // 5. recursive
        return fun(root, nullptr, nullptr);
    }
private:
    bool fun(TreeNode* root, int* min_val, int* max_val) {
        if (!root) return true;
        if ((max_val && root->val >= *max_val) || (min_val && root->val <= *min_val)) return false;
        return fun(root->left, min_val, &(root->val)) && 
               fun(root->right, &(root->val), max_val);
    }
    // time complexity: O(n)
    // space complexity: O(h)
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // method 2: sort (inorder traversal)
        // 1. if the tree is valid BST, its inorder traversal will stratify sorted property 
        previous = nullptr;
        return inorder(root);
    }
private:
    TreeNode* previous;
    
    bool inorder(TreeNode* root) {
        if (!root) return true;
        if (!inorder(root->left)) return false;
        if (previous && root->val <= previous->val) return false;
        previous = root;
        return inorder(root->right);
    }
    // time complexity: O(n)
    // space complexity: O(h)
};