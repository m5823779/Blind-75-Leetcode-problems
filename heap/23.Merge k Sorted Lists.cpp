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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // method 1: priority queue (min heap)
        // example:
        // [1, 4, 5]
        // [1, 3, 4]
        // [2, 6]
        // priority queue       ans
        // [1, 1, 2]            {}
        // [1, 2, 4]            {1}
        // [2, 3, 4]            {1, 1}
        // [3, 4, 6]            {1, 1, 2}
        // [4, 4, 6]            {1, 1, 2, 3}
        // [4, 5, 6]            {1, 1, 2, 3, 4}
        // [5, 6]               {1, 1, 2, 3, 4, 4}
        // [6]                  {1, 1, 2, 3, 4, 4, 5}
        // []                   {1, 1, 2, 3, 4, 4, 5, 6}
        
        // 1. create priority queue to store the first element of each list
        // 2. while priority queue is not empty, pop out top element
        // 3. push next element
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        auto comp = [](auto& a, auto& b){return a->val > b->val;};
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for(auto& list : lists) {
            if(list) pq.push(list);
        }
        
        while(!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            
            tail = tail->next;
            if(tail->next) pq.push(tail->next);
        }
        
//         while(!pq.empty()) {
//             tail->next = new ListNode(pq.top()->val);
//             tail = tail->next;
            
//             ListNode* tmp = pq.top();
//             pq.pop();
            
//             if(tmp->next) pq.push(tmp->next);
//         }
        return dummy.next;
    }
    // time complexity: O(nklogk) k: number of list / n: length of exah list
    // space complexity: O(k)
};