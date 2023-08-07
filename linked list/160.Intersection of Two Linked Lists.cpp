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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // method 1: hash set
        unordered_set<ListNode*> s;
        while (headA) {
            s.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (s.find(headB) != s.end()) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
    // time complexity: O(max(m, n))
    // space complexity: O(m)
};


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // method 2: 
        ListNode* i = headA;
        ListNode* j = headB;
        while (i != j) {
            i = i ? i->next : headB;
            j = j ? j->next : headA;
        }
        return i;
    }
};