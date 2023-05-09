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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root->left && !root->right) return {root->val};
    
        vector<int> ans;
        ans.push_back(root->val);
        getLeft(root->left, ans);
        getLeaf(root, ans);
        getRight(root->right, ans);
        return ans;
    }
private:
    void getLeft(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (!root->left && !root->right) return;  // pass leaf node
        
        ans.push_back(root->val);
        if (root->left) {
            getLeft(root->left, ans);
        }
        else {
            getLeft(root->right, ans);
        }
    }
    
    void getLeaf(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(root->val);  // add leaf node to answer
        }
        getLeaf(root->left, ans);
        getLeaf(root->right, ans);
    }
    
    void getRight(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (!root->left && !root->right) return;  // pass leaf node
        
        if (root->right) {
            getRight(root->right, ans);
        }
        else {
            getRight(root->left, ans);
        }
        ans.push_back(root->val);
    }
};

int main()
{
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    root->right = new TreeNode(22);
    root->right->right = new TreeNode(25);
    Solution solver;
    vector<int> ans = solver.boundaryOfBinaryTree(root);
    for (int i : ans) {
        cout << i << "\t";
    }
    return 0;
}