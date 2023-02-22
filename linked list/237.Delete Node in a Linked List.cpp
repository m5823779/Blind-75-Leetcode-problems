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
    void deleteNode(ListNode* node) {
        ListNode* tmp;
        if (node && node->next) tmp = node->next->next;
        else tmp = nullptr;
        node->val = node->next->val;
        node->next = tmp;
    }
};