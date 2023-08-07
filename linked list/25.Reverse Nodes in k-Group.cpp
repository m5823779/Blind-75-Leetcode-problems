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
        // method 1: Iterative
        // calculate length of linked list
        ListNode* cur = head;
        int len = 0;
        while (cur) {
            len++;
            cur = cur->next;
        }

        // how many group need to reverse
        int group = len / k;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode* tail = &dummy;

        cur = head;
        for (int j = 0; j < group; j++) {
            ListNode* pre = nullptr;
            ListNode* next = nullptr;
            for (int i = 0; i < k; i++) {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            head->next = cur;
            tail->next = pre;
            tail = head;
            head = cur;
        }
        return dummy.next;
    }
};