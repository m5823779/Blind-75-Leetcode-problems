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
    bool isPalindrome(ListNode* head) {
        // method 2: two pointer
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half (node after slow pointer)
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (slow) {
            next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        // two pointers
        ListNode* l = head;
        ListNode* r = pre;
        while (l && r) {
            if (l->val != r->val) return false;
            l = l->next;
            r = r->next;
        }
        return true;
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
    bool isPalindrome(ListNode* head) {
        // method 2: two pointer
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half (node after slow pointer)
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (slow) {
            next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        // two pointers
        ListNode* l = head;
        ListNode* r = pre;
        while (l && r) {
            if (l->val != r->val) return false;
            l = l->next;
            r = r->next;
        }
        return true;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};