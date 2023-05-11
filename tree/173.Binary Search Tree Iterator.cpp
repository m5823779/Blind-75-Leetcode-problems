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
class BSTIterator {
private:
    vector<int> data;
    int i = 0;

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return data[i++];
        // time complexity: O(1)
    }
    
    bool hasNext() {
        return i >= data.size() ? false : true;
        // time complexity: O(1)
    }
private:
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        data.push_back(root->val);
        inorder(root->right);
        // time complexity: O(n)
        // space complexity: O(n)
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */




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
class BSTIterator {
private:
    stack<TreeNode*> s;

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        TreeNode* tmp = s.top();
        s.pop();
        inorder(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !s.empty();    
    }

private:
    void inorder(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
        }
        // time complexity: O(n)
        // space complexity: O(h)    
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */