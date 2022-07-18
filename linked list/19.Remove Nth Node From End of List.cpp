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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // method 1: iterative
        // 1. enumerate link list to get length "len"
        // 2. create dummy to prevent remove head
        // 3. enumerate i, [0, len - n)
        
        int len = 0;
        ListNode* tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        for (int i = 0; i < len - n; i++) {
            tail->next = head;
            tail = tail->next;
            head = head->next;
        }
        
        ListNode* skip = head->next;
        tail->next = skip;

        return dummy.next;
    }
    // time complexity: O(2n)
    // space complexity: O(1)
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // method 1: two pointer
        // 1. create dummy to prevent head
        // 2. create left & right pointer point to dummy
        // 3. move right pointer n times
        // 4. move both right & left pointer if right.next is not NULL
        // 5. declear previous equal to left
        // 6. declear skip equal to previous.next.next
        // 7. left pointer to skip
        // 8. return dummy.next
        
        //  Dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
        //                          x
        //    L           R
        //           L         R
        //                L         R
        //                     L         R
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* left = dummy;
        ListNode* right = dummy;
        
        for (int i = 0; i < n; ++i) {
            right = right->next;
        }
        
        while(right->next) {
            left = left->next;
            right = right->next;
        }
        
        ListNode* previous = left;
        ListNode* skip = previous->next->next;
        left->next = skip;
        return dummy->next;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};