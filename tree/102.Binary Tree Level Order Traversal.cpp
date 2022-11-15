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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // method: BFS (breadth first search)
        // 1. create queue to store root node
        // 2. pop out all element in queue, then push their child node, while queue is not empty
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int s = q.size();
            vector<int> sub_ans = {};
            
            for (int i = 0; i < s; ++i) {
                TreeNode* tmp = q.front();
                sub_ans.push_back(tmp->val);

                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                
            }
            ans.push_back(sub_ans);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(h)
};