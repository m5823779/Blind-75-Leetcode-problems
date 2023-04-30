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
        // method 1: BFS (breadth first search) [Best]
        // 1. create queue to store root node
        // 2. pop out all element in queue, then push their child node, while queue is not empty
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
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
    // time complexity: O(n)  // every node entry queue once
    // space complexity: O(n / 2) -> O(n)  // create sub_ans
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // method 1.1: BFS (breadth first search) without queue
        // 1. create two vectors "current" & "next"
        //      "current": one for storage current root node
        //      "nmext": for storage their child node
        // 2. while "current" vector is not empty push empty vector {} into ans
        // 3. iterate all TreeNode into "current" vector, and push valuate into vector which just create in step 2
        // 4. push their chile node into "next" vector
        // 5. copy "next" to "current", and clear "next" vector
        
        if (!root) return {};
        vector<vector<int>> ans;
        vector<TreeNode*> current, next;
        
        current.push_back(root);
        while (!current.empty()) {
            ans.push_back({});
            for (auto node : current) {
                ans.back().push_back(node->val);
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            
            current = next;
            next.clear();
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n / 2) -> O(n)  // create current & next vector
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // method 2: DFS (depth first search)
        // 1. recursive, until root node is null, for each recursive depth plus one
        // 2. base on depth, push value into corresponding index for ans 
        
        //              1
        //           /     \
        //          2       3
        //        /   \   /   \
        //       4     5 6     7
        //
        //  node     depth      ans
        //   1         1        {{1}}
        //   2         2        {{1}, {2}}
        //   4         3        {{1}, {2}, {4}}
        //   5         3        {{1}, {2}, {4, 5}}
        //   3         2        {{1}, {2, 3}, {4, 5}}
        //   6         3        {{1}, {2, 3}, {4, 5, 6}}
        //   7         3        {{1}, {2, 3}, {4, 5, 6, 7}}
        
        vector<vector<int>> ans;
        DFS(root, 0, ans);
        return ans;
    }
private:
    void DFS(TreeNode* root, int depth, vector<vector<int>>& ans) {
        if (!root) return;
        while(ans.size() <= depth) ans.push_back({});
        
        ans[depth].push_back(root->val);
        
        DFS(root->left, depth + 1, ans);
        DFS(root->right, depth + 1, ans);
    }
    // time complexity: O(n)
    // space complexity: O(h)
};