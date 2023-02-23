/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* c = head;
        while (c) {
            len++;
            c = c->next;
        }

        vector<ListNode*> ans;
        int s = len / k;  // each set have s element
        int r = len % k;  // r set have one more element
        int ss;
        ListNode* pre = nullptr;

        for (int i = 0; i < k; i++) {
            ans.push_back(head);

            if (r) { ss = s + 1; }
            else { ss = s; }
            
            for (int j = 0; j < ss; j++) {
                pre = head;
                head = head->next;
            }
            if (pre) pre->next = nullptr;
            if (r) { r--; }
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(k)
};