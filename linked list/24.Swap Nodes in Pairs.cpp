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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        tail->next = head;

        ListNode* l = head;
        ListNode* r = head->next;
        while (l && r) {
            ListNode* tmp1 = (l && l->next) ? l->next->next : nullptr;
            ListNode* tmp2 = (r && r->next) ? r->next->next : nullptr;

            r->next = l;
            l->next = tmp1;

            tail->next = r;
            tail = l;
            
            l = tmp1;
            r = tmp2;            
        }
        return dummy.next;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};