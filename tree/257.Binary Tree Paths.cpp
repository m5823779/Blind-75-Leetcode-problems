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
    vector<string> binaryTreePaths(TreeNode* root) {
        // method 1: DFS recursive approach
        string path;
        dfs(root, path);
        return ans;
    }
private:
    vector<string> ans;
    void dfs(TreeNode* root, string path) {
        if (!root) return;
        if (!root->left && !root->right) {
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        dfs(root->left, path + to_string(root->val) + "->");
        dfs(root->right, path + to_string(root->val) + "->");
    }
    // time complexity: O(n)
    // space complexity: O(h)
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
    vector<string> binaryTreePaths(TreeNode* root) {
        // method 2: BFS iterative approah
        vector<string> ans;
        queue<TreeNode*> q;
        queue<string> path;

        if (root) {
            q.push(root);
            path.push(to_string(root->val));
        }

        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();

            string cur_path = path.front();
            path.pop();

            // leaf node
            if (!tmp->left && !tmp->right) {
                ans.push_back(cur_path);
            }

            if (tmp->left) {
                q.push(tmp->left);
                path.push(cur_path + "->" + to_string(tmp->left->val));
            }
            if (tmp->right) {
                q.push(tmp->right);
                path.push(cur_path + "->" + to_string(tmp->right->val));
            }
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};