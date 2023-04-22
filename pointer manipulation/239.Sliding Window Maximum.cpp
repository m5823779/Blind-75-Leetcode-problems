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
        // method 2: heap
        const int n = nums.size();
        multiset<int> s;  // small -> big
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(s.find(nums[i - k]));
            }
            if (i >= k - 1) {
                ans.push_back(*s.rbegin());
            }
        }
        return ans;
    }
    // time complexity: O(nlogk)
    // space complexity: O(k)
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // method 3: monotonic queue
        vector<int> ans;
        deque<int> d;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!d.empty() && d.front() <= i - k) {
                d.pop_front();
            }
            
            while (!d.empty() && nums[i] >= nums[d.back()]) {
                d.pop_back();
            }

            d.push_back(i);

            if (i >= k - 1) {
                ans.push_back(nums[d.front()]);
            }
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(k)
};