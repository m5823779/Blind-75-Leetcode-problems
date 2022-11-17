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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // method 1: recursive
        
        // example: 
        // preorder [3, 9, 20, 15, 7]
        // inorder [9, 3, 15, 20, 7]
        
        // 1. find the binary tree's root node in the preorder array's first element
        // 2. find the root node's position in inorder array, partitioning into two parts.
        //        left: left sub-tree, its length is n
        //        right: right sub-tree, its length is m
        // 3. go back to preorder array, for sub-array, first n elements is left sub-tree, last m elements is right sub-tree. 
        // 4. repeat step 1~3
        
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    
private:    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root_ind, int start, int end) {
        if (start > end) return NULL;
        int root_val = preorder[root_ind];
        
        TreeNode* node = new TreeNode(root_val);
        
        int mid_ind;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == root_val) mid_ind = i;
        }
        
        node->left = build(preorder, inorder, root_ind + 1, start, mid_ind - 1);
        node->right = build(preorder, inorder, root_ind + 1 + (mid_ind - start), mid_ind + 1, end);
        return node;
    }
    // time complexity: O(n^2)
    // space complexit: O(h)
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // method 2: recursive + hash table
        
        // example: 
        // preorder [3, 9, 20, 15, 7]
        // inorder [9, 3, 15, 20, 7]
        
        // 1. find the binary tree's root node in the preorder array's first element
        // 2. find the root node's position in inorder array, partitioning into two parts.
        //        left: left sub-tree, its length is n
        //        right: right sub-tree, its length is m
        // 3. go back to preorder array, for sub-array, first n elements is left sub-tree, last m elements is right sub-tree. 
        // 4. repeat step 1~3
        unordered_map<int, int> m; // <val, index>
        for (int i = 0; i < inorder.size(); ++i) m[inorder[i]] = i;
        
        return build(preorder, m, 0, 0, inorder.size() - 1);
    }
    
private:    
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& m, int root_ind, int start, int end) {
        if (start > end) return NULL;
        int root_val = preorder[root_ind];
        
        TreeNode* node = new TreeNode(root_val);
        
        int mid_ind = m[root_val];

        node->left = build(preorder, m, root_ind + 1, start, mid_ind - 1);
        node->right = build(preorder, m, root_ind + 1 + (mid_ind - start), mid_ind + 1, end);
        
        return node;
    }
    // time complexity: O(n)
    // space complexit: O(h)
};