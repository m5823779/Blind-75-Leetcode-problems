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
    // method: DFS
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string res = to_string(root->val) + ",";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
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
            else {
                tmp += c;
            }
        }
        return decode(q, INT_MIN, INT_MAX);
    }

private:
    TreeNode* decode(queue<string>& q, int minBound, int maxBound) {
        if (q.empty()) return nullptr;
        string tmp = q.front();
        int val = stoi(tmp);
        if (val > minBound && val < maxBound) {
            q.pop();
            TreeNode* root = new TreeNode(val);
            root->left = decode(q, minBound, val);
            root->right = decode(q, val, maxBound);
            return root;
        }
        else {
            return nullptr;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;