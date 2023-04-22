class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // method 1: brute force
        const int n = nums.size();
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= target) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // method 2: sliding window
        const int n = nums.size();
        int ans = n + 1;
        int sum = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
    // time complexity: O(n)
    // spac ecomplexity: O(1)
};