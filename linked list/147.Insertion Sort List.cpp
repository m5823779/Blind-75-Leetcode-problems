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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur) {
            if (cur->val >= pre->val) {
                pre = cur;
                cur = cur->next;
            }
            else {
                ListNode* next = cur->next;
                pre->next = next;

                ListNode* insert_id = &dummy;
                while (cur->val > insert_id->next->val) {
                    insert_id = insert_id->next;
                }

                ListNode* after = insert_id->next;
                insert_id->next = cur;
                cur->next = after;

                cur = next;
            }
        }
        return dummy.next;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};
