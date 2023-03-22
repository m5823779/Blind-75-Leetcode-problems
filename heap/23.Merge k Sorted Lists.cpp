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


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // method 2: divide and conquer
        // example:
        //            a+b+c+d
        //          /         \
        //       a+b           c+d
        //      /   \         /    \
        //    a       b     c        d 
        return solve(lists, 0, lists.size() - 1);
    }
private:
    ListNode* solve(vector<ListNode*>& lists, int l, int r) {
        if (l > r) return nullptr;  // to avoid empty lists
        if (l == r) return lists[l];
        if (r - l == 1) return mergeTwoList(lists[l], lists[r]);
        int m = l + (r - l) / 2;
        
        ListNode* l1 = solve(lists, l, m);
        ListNode* l2 = solve(lists, m + 1, r);
        return mergeTwoList(l1, l2);
    }
    
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    // time complexity: O(min(n, m) * logk) k: number of list / n: length of exah list
    // space complexity: O(logk)
};