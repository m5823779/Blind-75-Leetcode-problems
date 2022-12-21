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
    TreeNode* invertTree(TreeNode* root) {
        // method: DFS (depth first search) recursive
        if (!root) return nullptr;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
        
        // time complexity: O(n)
        // space complexity: O(n)
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // method 2: BFS
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            
            if (n) {
                TreeNode* tmp = n->left;
                n->left = n->right;
                n->right = tmp;

                q.push(n->left);
                q.push(n->right);
            }      
        }
        return root;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};