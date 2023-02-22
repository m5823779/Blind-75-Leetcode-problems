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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (int i = 0; i < left - 1; i++) {
            tail->next = head;
            tail = tail->next;
            head = head->next;
        }

        ListNode* next = nullptr;
        ListNode* previous = nullptr;
        ListNode* current = head;

        for (int i = left; i <= right; i++) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head->next = current;
        tail->next = previous;
        return dummy.next;
    }
};