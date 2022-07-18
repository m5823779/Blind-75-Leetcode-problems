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
    void reorderList(ListNode* head) {
        // method: two pointer
        // 1. find middle
        //      declear slow & fast pointer (slow.next), slow move one step, fast move two step every iterative
        // 2. ListNode "l1" start from head, ListNode "l2" start from slow pointer
        // 3. reverse ListNode "l2"
        // 4. merge ListNode "l1" and "l2"
    
        // example:
        // 1 -> 2 -> 3 -> 4 -> 5
        // reverse(4 -> 5)
        // merge(1 -> 2 -> 3, 5 -> 4)
        
        // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
        // s    f
        //      s         f
        //           s               f
        
        // find middle
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head->next;
        
        while(fast_ptr && fast_ptr->next) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        
        // reverse link list
        ListNode* l2 = slow_ptr->next;
        
        // very important
        slow_ptr->next = nullptr;

        ListNode* next = nullptr;
        ListNode* previous = nullptr;
        
        while(l2) {
            next = l2->next;
            l2->next = previous;
            previous = l2;
            l2 = next;
        }

        // merge link list
        ListNode* l1 = head;
        l2 = previous;

        while(l2) {
            ListNode* tmp1 = l1->next;
            ListNode* tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
    // time complexity: O(n)
    // space complexity: O(1)
};