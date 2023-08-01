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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        // method 1: hash table
        // 1->2->3->2
        // map
        // value,  count
        //  1        1
        //  2        2
        //  3        1
        unordered_map<int, int> mp;  // <value, count>
        ListNode* cur = head;
        while (cur) {
            mp[cur->val]++;
            cur = cur->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        cur = head;
        while (cur) {
            if (mp[cur->val] > 1) {
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

