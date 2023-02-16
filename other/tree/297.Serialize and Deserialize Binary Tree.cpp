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
    // method: DFS (preorder traversal)
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        encode(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string tmp;
        for (char c : data) {
            if (c == ',') {
                q.push(tmp);
                tmp = "";
            }
            else {
                tmp += c;
            }
        }
        return decode(q);
    }
private:
    void encode(TreeNode* root, string& ans) {
        if (!root) {
            ans += "null,";
            return;
        }
        ans += to_string(root->val) + ",";
        encode(root->left, ans);
        encode(root->right, ans);   
    }

    TreeNode* decode(queue<string>& data) {
        string tmp = data.front();
        data.pop();
        if (tmp == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = decode(data);
        node->right = decode(data);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));