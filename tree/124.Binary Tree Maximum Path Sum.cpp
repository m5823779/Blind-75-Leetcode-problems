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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        // method: recursive 
        //      |
        //      a
        //    /   \
        //   b     c
        // /   \ /   \
        //
        // choose 1 from 2 (b + a / c + a) => recursive leaf node, until null 
        //                 (not return root node, so update max value to global max value) 
        // choose 2 from 3 (b + a + c / b + a / c + a) => update global max value 
        maxPathSum(root, ans);
        return ans;
    }
private:
    int maxPathSum(TreeNode* root, int& ans) {  // b + a or c + a or b + a + c
        if (!root) return 0;
        int left = max(0, maxPathSum(root->left, ans));
        int right = max(0, maxPathSum(root->right, ans));
        int left_mid_right = left + root->val + right;
        int leftright_mid = max(left, right) + root->val;
        ans = max(ans, max(left_mid_right, leftright_mid));
        return leftright_mid;
    }
    
    // time complexity: O(n)
    // space complexity: O(h)
};