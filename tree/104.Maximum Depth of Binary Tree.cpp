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
    int maxDepth(TreeNode* root) {
        // method 1: DFS (depth first search)
        // return 0, if node is null
        // 1 + max(left node, right node)
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    // time complexity: O(n)
    // space complexity: O(h)
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        // method 2: BFS (Breadth first search)
        // 1. return 0, if root is null
        // 2. create queue to store root node
        // 3. pop out original root node, then push next (left, right) node into queue, while queue is not empty
        if (!root) return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            ans++;
            int s = q.size();
            
            for (int i = 0; i < s; ++i) {
                TreeNode* tmp = q.front();
                q.pop();
                
                if (tmp->right) q.push(tmp->right);
                if (tmp->left) q.push(tmp->left);
            }
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(h) 
};