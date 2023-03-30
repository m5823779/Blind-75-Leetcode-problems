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
                tmp = "";
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