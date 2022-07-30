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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // method 1: iterative 
        // 1. create "dummy" ListNode to store head address
        // 2. create "tail" ListNode, pointer to dummy
        // 3. while list1 and list2 not NULL
        //      if (list1.val < list2.val) tail.next = list1, list1 = list1.next, tail = tail.next
        //      if (list1.val >= list2.val) tail.next = list2, list2 = list2.next, tail = tail.next
        // 4. if list1 or list2 is not NULL
        //      if (list1) tail.next = list1
        //      if (list2) tail.next = list2
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;
        
        return dummy.next;
        // time complexity: O(min(m, n))
        // space complexity: O(m + n)
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // method 2: recursive 
        //  merge(a, b)
        //  return b, if a is NULL
        //  return a, if b is NULL
        //  a[0] + merge(a.next, b), if a.val < b.val
        //  b[0] + merge(a, b.next), if a.val >= b.val
        
        // example:
        // l1: [1, 3, 5, 6]
        // l2: [2, 4]
        // [1] + mergeTwoLists([3, 5, 6], [2, 4])
        // [2] + mergeTwoLists([3, 5, 6], [4])
        // [3] + mergeTwoLists([5, 6], [4])
        // [4] + mergeTwoLists([5, 6])
        // [5, 6] 
        
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        // time complexity: O(max(m, n))
        // space complexity: O(max(m, n))
    }
};