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
        // method: DFS
        if (!root) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);  // cause val may >= 10 or < 0, so we need add ","
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q; // cause val may >= 10 or < 0 (have char '-') so we cant use pointer point to the string
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
        return decode(q);
    }

private:
    TreeNode* decode(queue<string>& q) {
        if (q.empty()) return nullptr;
        string s = q.front();
        q.pop();

        if (s == "#") {
            return nullptr;
        }
        else {
            TreeNode* root = new TreeNode(stoi(s));
            root->left = decode(q);
            root->right = decode(q);
            return root;
        }
    }
    // time complexity: O(n)
    // space complexity: O(n)
};



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // method: BFS
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();

            if (!tmp) {
                res += "#,";
            }
            else {
                res += to_string(tmp->val) + ",";
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> buffer;
        string tmp;
        for (const char& c : data) {
            if (c == ',') {
                buffer.push_back(tmp);
                tmp.clear();
            }
            else {
                tmp += c;
            }
        }

        if (buffer[0] == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(buffer[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (i < buffer.size()) {
            TreeNode* tmp = q.front();
            q.pop();

            if (buffer[i] != "#") {
                tmp->left = new TreeNode(stoi(buffer[i]));
                q.push(tmp->left);
            }
            i++;

            if (buffer[i] != "#") {
                tmp->right = new TreeNode(stoi(buffer[i]));
                q.push(tmp->right);
            }
            i++;
        }
        return root;
    }
};