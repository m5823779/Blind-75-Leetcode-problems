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
        // method 1: BFS
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int s = q.size();
            Node* prev = nullptr;
            for (int i = 0; i < s; i++) {
                Node* tmp = q.front();
                q.pop();
                if (prev) {
                    prev->next = tmp;
                }
                prev = tmp;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return root;
    }
};


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
        if (!root) return nullptr;
        Node* cur = root;
        Node* pre = nullptr;
        Node* head = nullptr;
        while (cur) {
            if (cur->left) {
                if (!head) {
                    head = cur->left;
                    pre = cur->left;
                }
                else {
                    pre->next = cur->left;
                    pre = pre->next;
                }
            }

            if (cur->right) {
                if (!head) {
                    head = cur->right;
                    pre = cur->right;
                }
                else {
                    pre->next = cur->right;
                    pre = pre->next;
                }
            }

            cur = cur->next;
            if (!cur) {
                cur = head;
                head = nullptr;
                pre = nullptr;
            }
        }
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        Node* next_layer = nullptr;
        Node* pre = nullptr;
        Node* cur = root;
        while (cur) {
            while (cur) {
                if (cur->left) {
                    if (!next_layer) next_layer = cur->left;
                    if (pre) {
                        pre->next = cur->left;
                    }
                    pre = cur->left;
                }
                if (cur->right) {
                    if (!next_layer) next_layer = cur->right;
                    if (pre) {
                        pre->next = cur->right;
                    }
                    pre = cur->right;
                }
                cur = cur->next;
            }

            cur = next_layer;
            next_layer = nullptr;
            pre = nullptr;
        }
        return root;
    }
};