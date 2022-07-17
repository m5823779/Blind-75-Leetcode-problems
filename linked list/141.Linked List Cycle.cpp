/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // method 1: hash set
        // 1. create unordered set to store the "memory address" that already visited
        // 2. if head == NULL, return false
        // 3. if current "memory address" already exist in unordered_set, return true
        // 4. if current "memory address" already not exist in unordered_set, insert it
        // 5. head = head.next
        
        unordered_set<ListNode*> visited;
        
        while(head) {
            if (visited.count(head)) return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        // method 2: two pointer (past & slow pointer)
        // 1. declear two pointer "fast_ptr" & "slow_ptr" to head
        // 2. while "fast_ptr" and "fast_ptr.next" is not NULL
        //      slow_ptr = slow_ptr.next
        //      fast_ptr = fast_ptr.next.next
        // 3. if (fast_ptr == slow_ptr) return true
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;

        
        while (fast_ptr && fast_ptr->next) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if (fast_ptr == slow_ptr) return true;
        }
        return false;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};