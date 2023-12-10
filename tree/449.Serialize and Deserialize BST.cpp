/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string tmp;
        for (char c : data) {
            if (c == ',') {
                q.push(tmp);
                tmp.clear();
            }
            else tmp += c;
        }
        return solve(q, INT_MIN, INT_MAX);
    }
    
    TreeNode* solve(queue<string>& q, int down, int up) {
        if (q.empty()) return nullptr;
        int tmp = stoi(q.front());
        if (tmp >= up || tmp <= down) return nullptr;
        else {
            q.pop();
            TreeNode* root = new TreeNode(tmp);
            root->left = solve(q, down, tmp);
            root->right = solve(q, tmp, up);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;