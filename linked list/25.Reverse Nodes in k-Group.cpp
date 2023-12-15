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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int l = 0;
        while (cur) {
            l++;
            cur = cur->next;
        }
        int g = l / k;
        
        ListNode dummy(-1);
        dummy.next = head;

        cur = head;
        ListNode* tail = &dummy;
        for (int i = 0; i < g; i++) {
            ListNode* pre = nullptr;
            ListNode* next = nullptr;
            for (int j = 0; j < k; j++) {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            ListNode* new_tail = tail->next;
            tail->next->next = cur;
            tail->next = pre;
            tail = new_tail;
        }
        return dummy.next;
    }
};