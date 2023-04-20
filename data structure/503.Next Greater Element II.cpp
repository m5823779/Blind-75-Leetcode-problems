class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // method 1: brute force 
        const int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int next_greater = -1;
            for (int j = i; j < n * 2; j++) {
                if (nums[j % n] > nums[i]) {
                    next_greater = nums[j % n];
                    break;
                }
            }
            ans.push_back(next_greater);
        }
        return ans;
    }
    // time compleixty: O(n * 2n)
    // space complexity: O(1)
};


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // method 2: monotonic stack (copy version) [end -> front]
        const int n = nums.size();
        nums.insert(nums.begin(), nums.begin(), nums.end());
        vector<int> ans(n, -1);
        stack<int> mono_s;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!mono_s.empty() && nums[i] >= mono_s.top()) {
                mono_s.pop();
            }
            if (!mono_s.empty() && i < n) {
                ans[i] = mono_s.top();
            }
            mono_s.push(nums[i]);
        }
        return ans;
    }
    // time compleixty: O(2n)
    // space complexity: O(2n)
};


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // method 2: monotonic stack (mod version) [front -> end]
        const int n = nums.size();
        vector<int> ans(n);

        stack<int> mono_stack;  // index
        for (int i = 0; i < n * 2; i++) {
            while (!mono_stack.empty() && nums[i % n] > nums[mono_stack.top() % n]) {
                if (!mono_stack.empty() && mono_stack.top() < n) {
                    ans[mono_stack.top()] = nums[i % n];
                }
                mono_stack.pop();
            }
            mono_stack.push(i);
        }
        while (!mono_stack.empty()) {
            if (mono_stack.top() < n) {
                ans[mono_stack.top()] = -1;
            }
            mono_stack.pop();
        }
        return ans;
    }
    // time complexity: O(2n)
    // space complexity: O(2n)
};