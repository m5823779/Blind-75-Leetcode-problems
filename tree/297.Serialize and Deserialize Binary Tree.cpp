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






 // The code is wrong, only work when it is complete binary tree
//-----------------------------------------
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encode;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            
            if (!tmp) {
                encode += 'n';
            }
            else {
                encode += to_string(tmp->val);
            }

            if (tmp) { 
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        cout << encode << endl;
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return decode(data, 0);
    }
private:
    TreeNode* decode(string data, int cur) {
        char c = data[cur];
        if (cur >= data.size()) {
            return nullptr;
        }
        if (c == 'n') {
            return nullptr;
        }
        cout << c << endl;
        TreeNode* root = new TreeNode(c - '0');
        
        // the formula only work when it is complete binary tree
        root->left = decode(data, 2 * cur + 1);
        root->right = decode(data, 2 * cur + 2);  
        return root;
    }
};
//-----------------------------------------