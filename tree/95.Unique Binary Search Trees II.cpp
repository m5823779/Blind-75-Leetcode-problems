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
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
private:
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> uniqueBST;
        if (start > end) {
            uniqueBST.push_back(nullptr);
            return uniqueBST;
        }

        for (int i = start; i <= end; i++) {        
            vector<TreeNode*> left_subtree = solve(start, i - 1);
            vector<TreeNode*> right_subtree = solve(i + 1, end);
            
            for (TreeNode* l : left_subtree) {
                for (TreeNode* r : right_subtree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    uniqueBST.push_back(root);
                }
            }
        }
        return uniqueBST;
    }
};