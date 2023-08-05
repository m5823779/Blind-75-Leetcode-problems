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


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // method 2: recursive
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode *new_head = reverseList (head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};


class Solution {
public:
    // method 2: recursive 
    ListNode* reverseList(ListNode* head) {
        return solve(head, NULL);
    }
private:
    ListNode* solve(ListNode* head, ListNode* previous) {
        // break condition
        if (!head) return previous;
        ListNode* next = head->next;
        head->next = previous;
        return solve(next, head);
    }
    // time complexity: O(n)
    // space complexity: O(n)
};

