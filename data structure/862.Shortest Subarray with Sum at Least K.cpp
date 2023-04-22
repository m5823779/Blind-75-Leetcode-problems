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