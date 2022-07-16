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
    // method 1. two pointer 
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* previous = nullptr;
        ListNode* next = nullptr;
        
        while (current) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
        
        return head;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};