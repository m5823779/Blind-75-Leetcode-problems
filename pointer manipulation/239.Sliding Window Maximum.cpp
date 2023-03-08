class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // method 1: brute force
        vector<int> ans;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            int max_val = nums[i];
            for (int j = 0; j < k; j++) {
                max_val = max(max_val, nums[i + j]);
            }
            ans.push_back(max_val);
        }
        return ans;
        // time complexity: O((n - k + 1) * k)
        // space complexity: O(1)
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // method 1: brute force
        vector<int> ans;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            vector<int>::iterator start = nums.begin() + i;
            vector<int>::iterator end = nums.begin() + i + k;
            ans.push_back(*max_element(start, end));
        }
        return ans;
        // time complexity: O((n - k + 1) * k)
        // space complexity: O(1)
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // method 2: sliding window (monotonic queue / deque)
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && i - k >= 0 && nums[i - k] == q.front()) {
                q.pop_front();
            }
            while (!q.empty() && nums[i] > q.back()) {
                q.pop_back();
            }
            q.push_back(nums[i]);
            if (i >= k - 1) {
                ans.push_back(q.front());
            }
        } 
        return ans;
        // time complexity: O(n)
        // space complexity: O(n)
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // method 2: sliding window (monotonic queue / deque)
        vector<int> ans;
        deque<int> q;
        const int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (!q.empty() && nums[r] > q.front()) {
                q.clear();
            }
            while (!q.empty() && nums[r] > q.back()) {
                q.pop_back();
            }

            q.push_back(nums[r]);
            if (r >= k - 1) {
                ans.push_back(q.front());
                if (nums[l] == q.front()) {
                    q.pop_front();
                }
                l++;
            }
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};