class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // method 1: brute force + Hash table
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        unordered_map<int, int> mp;  // nums2[i], first element which > nums2[i]
        for (int i = 0; i < n2; i++) {
            int next_greater = -1;
            for (int j = i + 1; j < n2; j++) {
                if (nums2[j] > nums2[i]) {
                    next_greater = nums2[j];
                    break;
                }
            }
            mp[nums2[i]] = next_greater;
        }

        vector<int> ans;
        for (int i = 0; i < n1; i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(n)
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // method 2: monotonic stack
        // stack 
        //  |
        //  |  |
        //  |  |  |
        // large -> small
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        unordered_map<int, int> mp;  // nums2[i] value / the first element which > nums2[i]
        stack<int> monotonic_stack;  // store index (cause value may not distinct)
        for (int i = 0; i < n2; i++) {
            // 1. maintain monotonic stack satisfy property
            while (!monotonic_stack.empty() && nums2[i] > nums2[monotonic_stack.top()]) {
                // 2. add the top element to ans
                mp[ nums2[monotonic_stack.top()] ] = nums2[i];
                monotonic_stack.pop();
            }
            // 3. push new element into stack
            monotonic_stack.push(i);
        }

        while (!monotonic_stack.empty()) {
            mp[nums2[monotonic_stack.top()]] = -1;
            monotonic_stack.pop();
        }

        vector<int> ans;
        for (int i = 0; i < n1; i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // method 3: monotonic stack (stack) [enumerate from back to front]
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        // next greater element of nums2
        vector<int> next_greater(n2, -1);
        stack<int> sk;
        for (int i = n2 - 1; i >= 0; i--) {
            // 1. maintain monotonic stack
            while (!sk.empty() && nums2[i] >= sk.top()) {
                sk.pop();
            }
            // 2. add top element of the stack to answer
            next_greater[i] = sk.empty() ? -1 : sk.top();

            // 3. push current elment to stack
            sk.push(nums2[i]);
        }

        // nums2[i] value, first element which > nums2[i]
        map<int, int> mp;
        for (int i = 0; i < n2; i++) {
            mp[nums2[i]] = next_greater[i];
        }

        vector<int> ans;
        for (int i = 0; i < n1; i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};