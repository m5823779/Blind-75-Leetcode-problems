/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        // method 1: Tree set
        set<Node*> p_parent;
        while (p) {
            p_parent.insert(p);
            p = p->parent;
        }
        while (q) {
            if (p_parent.find(q) != p_parent.end()) return q;
            q = q->parent;
        }
        return nullptr;
    }
    // time complexity: O(h)
    // space complexity: O(h)
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        // method 2:
        Node* a = p;
        Node* b = q;
        while (a != b) {
            a = (a->parent == nullptr) ? q : a->parent;
            b = (b->parent == nullptr) ? p : b->parent;
        }
        // return a;
        return b;
    }
    // time complexity: O(h)
    // space complexity: O(1)
};