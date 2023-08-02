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
    ListNode* partition(ListNode* head, int x) {
        ListNode newHead(-1);
        newHead.next = head;

        ListNode* pre = &newHead;
        ListNode* cur = head;

        ListNode greater(-1);
        ListNode* tail = &greater;

        while (cur) {
            // case 1: < x (left side)
            if (cur->val < x) {
                pre = cur;
                cur = cur->next;
            }
            // case 2: >= x (right side)
            else {
                tail->next = cur;
                tail = tail->next;

                pre->next = cur->next;
                cur = cur->next;
            }
        }

        tail->next = nullptr;
        pre->next = greater.next;
        return newHead.next;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less(-1);
        ListNode greater(-1);
        ListNode* l = &less;
        ListNode* g = &greater;

        while (head) {
            // case 1: < x (left side)
            if (head->val < x) {
                l->next = head;
                l = l->next;
            }
            // case 2: >= x (right side)
            else {
                g->next = head;
                g = g->next;
            }
            head = head->next;
        }

        g->next = nullptr;
        l->next = greater.next;
        return less.next;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};