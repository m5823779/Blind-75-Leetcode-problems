/******************************************************************************
深度串列：
給定一顆二元樹，請設計一個演算法，建立每個深度的所有節點的串列
        1
      /   \
     2     3
      \   /  \
       4 5   6

output:
1->null
2->3->null
4->5->6->null
*******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<ListNode*> depth2List(TreeNode* root) {
    vector<ListNode*> ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        int s = q.size();
        for (int i = 0; i < s; i++) {
            TreeNode* tmp = q.front();
            q.pop();
            
            tail->next = new ListNode(tmp->val);
            tail = tail->next;
            
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        ans.push_back(dummy.next);
    }
    return ans;
}

void printList (ListNode* head) {
    cout << head->val;
    head = head->next;
    while (head) {
        cout << ", " << head->val;
        head = head->next;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    vector<ListNode*> lists = depth2List(root);
    for (ListNode* list : lists) {
        printList(list);
    }
    return 0;
}
