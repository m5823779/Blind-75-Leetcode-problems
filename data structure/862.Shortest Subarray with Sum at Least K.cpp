class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // method 1: brute force
        const int n = nums.size();
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= k) {
                    ans = min(ans, j - i + 1);
                }
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // method 2: monotonic queue (sliding window)
        const int n = nums.size();
        // prefix sum   
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = nums[i] + prefix_sum[i];
        }


        int ans = n + 1;
        // sum[i-j] = prefix[j] = prefix[i - 1]
        // sum[i-j] find subarray sum >= k
        // prefix[j] > prefix[i - 1]
        // use monotonic queue (increasing)
        deque<int> d;
        for (int i = 0; i < n + 1; i++) {
            // pop back to maintain increasing 
            while (!d.empty() && prefix_sum[i] < prefix_sum[d.back()]) {
                d.pop_back();
            }
            // pop front to find shorter answer
            while (!d.empty() && prefix_sum[i] - prefix_sum[d.front()] >= k) {
                // caculate answer
                ans = min(ans, (i - d.front() + 1) - 1);
                d.pop_front();
            }
            // push back current prefix
            d.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};