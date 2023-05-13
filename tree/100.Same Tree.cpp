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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // method: brute force
        // consider                              same
        // case 1. p = null & q = null           true
        // case 2. p = a , q = null              false
        // case 3. p = null, q = b               false
        // case 4. p = a, q = b                  false
        // case 5. p = a & q = a &
        //         isSameTree(p->left, q->left)
        //         isSameTree(p->right, q->right) true
        
        // both root node are null
        if (!p && !q) return true;
        
        // one of root node is null, the other not
        else if (!p || !q) return false;
        
        // both root node are not null, but value is differen
        else if (p->val != q->val) return false;
        
        // both root node are not null, both val are the same, check left and right child
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // method: BFS
        queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        while (!queue.empty()){
            TreeNode * q2=queue.front();
            queue.pop();
            TreeNode * q1=queue.front();
            queue.pop();
            if (!q1 && !q2) continue;
            if (!q1 || !q2) return false;
            if (q1->val != q2->val) return false;
            queue.push(q1->left);
            queue.push(q2->left);
            queue.push(q1->right);
            queue.push(q2->right);
        }
        return true;
    }
};