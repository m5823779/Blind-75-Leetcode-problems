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
    double ans;
    double maximumAverageSubtree(TreeNode* root) {
        // method: DFS (postoreder)
        solve(root);
        return ans;
    }
private:
    vector<int> solve(TreeNode* root) {
        vector<int> res(2, 0);  // <sum, number of the nodes for the subtree>
        if (!root) return res;
        vector<int> leftInfo = solve(root->left);
        vector<int> rightInfo = solve(root->right);
        res[0] = leftInfo[0] + rightInfo[0] + root->val;
        res[1] = leftInfo[1] + rightInfo[1] + 1;
        if ((double)res[0] / (double)res[1] > ans) {
            ans = (double)res[0] / (double)res[1];
        }
        return res;
    }
};