class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // [1, 2, 3], target = 4
        // dp[0] = 1
        // dp[1] = dp[1 - 1] + dp[1 - 2] + dp[1 - 3] = 1
        // dp[2] = dp[2 - 1] + dp[2 - 2] + dp[2 - 3] = 2
        // dp[3] = dp[3 - 1] + dp[3 - 2] + dp[3 - 3] = 4
        // dp[4] = dp[4 - 1] + dp[4 - 2] + dp[4 - 3] = 7
        
        // method: dynamic programming
        // 1. create vector "dp" to store result, which size = target + 1, and dp[0] = 1
        // 2. enumerate i [1, target]
        // 3. enumerate nums[j]
        // 4. dp[i] += dp[i - nums[j]]
        // 5. return dp[target]
        
        const int n = nums.size();
        vector<int> dp(target + 1);
        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - nums[j] >= 0) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
        // time complexity: O(m * n)
        // space complexity: O(m)
    }
};