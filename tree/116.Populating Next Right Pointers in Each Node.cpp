/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // method: BFS
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                Node* tmp = q.front();
                q.pop();
                if (i == s - 1) {
                    tmp->next = nullptr;
                }
                else {
                    tmp->next = q.front();
                }

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return root;
    }
    // time complexity: O(n)
    // space compleixty: O(n)
};


class Solution {
public:
    Node* connect(Node* root) {
        // method: DFS (pre-ordered)
        if (!root || !root->left) return root;

        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
    // time complexity: O(n)
    // space cemplexity: O(logn)
};


class Solution {
public:
    Node* connect(Node* root) {
        // method: BFS (optimize space)
        Node* cur = root;
        Node* nxt = root ? root->left : nullptr;
        while (cur && nxt) {
            cur->left->next = cur->right;
            if (cur->next) {
                cur->right->next = cur->next->left;
                cur = cur->next;
            }
            else {
                cur = nxt;
                nxt = cur->left;
            }
        }
        return root;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};