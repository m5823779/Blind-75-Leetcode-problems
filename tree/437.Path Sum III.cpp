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
    int pathSum(TreeNode* root, int targetSum) {
        // method 1: Brute force (DFS)
        if (!root) return 0;
        return solve(root, targetSum) +
               pathSum(root->left, targetSum) + 
               pathSum(root->right, targetSum);
    }
    int solve(TreeNode* root, long targetSum) {
        if (!root) return 0;
        int res = 0;
        if (root->val == targetSum) res += 1;
        res += solve(root->left, targetSum - root->val) + 
               solve(root->right, targetSum - root->val);
        return res; 
    }
    // time complexity: O(n^2)
};


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
    // method 2: DFS + hash map + prefix sum
    int ans = 0;
    int target = 0;
    unordered_map<long, int> mp;
    int pathSum(TreeNode* root, int targetSum) {
        target  = targetSum;
        mp[0] = 1;
        solve(root, 0);
        return ans;
    }
    void solve(TreeNode* root, long prefix_sum) {
        if (!root) return;
        prefix_sum += root->val;
        long remain = prefix_sum - target;
        if (mp.find(remain) != mp.end()) ans += mp[remain];

        mp[prefix_sum]++;
        solve(root->left, prefix_sum);
        solve(root->right, prefix_sum);
        mp[prefix_sum]--;
    }
    // time complexity: O(n)
};