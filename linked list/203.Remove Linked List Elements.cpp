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
    ListNode* removeElements(ListNode* head, int val) {
        // method 1: two pointers
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy.next;   
    }
    // time complexity: O(n)
    // space complexity: O(1)
};


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
    ListNode* removeElements(ListNode* head, int val) {
        // method 2: Recursive
        if (!head) return nullptr;
        ListNode* nxt = removeElements(head->next, val);
        if (head->val == val) {
            return nxt;
        }
        else {
            head->next = nxt;
            return head;
        }
    }
    // time complexity: O(n)
    // space complexity: O(n)
};

