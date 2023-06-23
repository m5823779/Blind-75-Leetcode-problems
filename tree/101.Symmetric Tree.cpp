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
    bool isSymmetric(TreeNode* root) {
        // method 1: DFS
        return solve(root->left, root->right);
    }
private:
    bool solve(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p || !q) return false;
        else if (p->val != q->val) return false;
        else return solve(p->left, q->right) && solve(p->right, q->left);
    }
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
    bool isSymmetric(TreeNode* root) {
        // method 2: BFS
        queue<TreeNode*> q;
        if (root) {
            q.push(root->left);
            q.push(root->right);
        }
        while (!q.empty()) {
            TreeNode* tmp1 = q.front();
            q.pop();

            TreeNode* tmp2 = q.front();
            q.pop();

            if (!tmp1 && !tmp2) continue;
            else if (!tmp1 || !tmp2) return false;
            else if (tmp1->val != tmp2->val) return false;
            else {
                q.push(tmp1->left);
                q.push(tmp2->right);
                
                q.push(tmp1->right);
                q.push(tmp2->left);
            }
        }
        return true;
    }
};