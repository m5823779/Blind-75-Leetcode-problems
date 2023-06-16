class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // method 1: recursion + memorization
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2) return false;
        else {
            int target = sum / 2;
            memo = vector<vector<int>>(nums.size(), vector<int>(target + 1, -1));
            return subset(nums, 0, target);
        }
    }
private:
    vector<vector<int>> memo;

    bool subset(vector<int>& nums, int cur, int target) {
        if (target == 0) return true;
        if (cur >= nums.size()) return false;

        if (memo[cur][target] != -1) return memo[cur][target];

        for (int i = cur; i < nums.size(); i++) {
            if (target - nums[i] >= 0) {
                if (subset(nums, i + 1, target - nums[i])) return true;
            }
        }
        return memo[cur][target] = false;
    }
    // time complexity: O(2^n) -> O(n * sum(nums))
    // space complexity: O(n)
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // method 1: recursion + memorization
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2) return false;
        else {
            int target = sum / 2;
            memo = vector<vector<int>>(nums.size(), vector<int>(target + 1, -1));
            return subset(nums, 0, target);
        }
    }
private:
    vector<vector<int>> memo;
    bool subset(vector<int>& nums, int cur, int target) {
        if (target == 0) return true;
        if (target < 0 || cur >= nums.size()) return false;

        if (memo[cur][target] != -1) return memo[cur][target];

        if (subset(nums, cur + 1, target - nums[cur]) || // pick current element
            subset(nums, cur + 1, target)) { // dont pick
            return true;
        }
        return memo[cur][target] = false;
    }
    // time complexity: O(2^n) -> O(n * sum(nums))
    // space complexity: O(n)
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // method 2: dynamic programming 
        const int n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2) return false;
        else {
            int target = sum / 2;
            // dp[i][j] : Are there any subset in nums[:i] equal to the target j
            vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

            // Initialize dp[i][0] as true cause the subset equal to noting the target will be 0
            for (int i = 0; i <= n; i++) dp[i][0] = true;

            for (int i = 1; i <= n; i++) {  // i : array "nums" indices
                for (int j = 1; j <= target; j++) {  // j : target sum
                    if (j == nums[i - 1]) {
                        dp[i][j] = true;
                    }
                    // pick
                    if (j - nums[i - 1] > 0 && dp[i - 1][j - nums[i - 1]]) dp[i][j] = true;
                    // no pick
                    if (dp[i - 1][j]) dp[i][j] = true;
                }
            }
            return dp[n][target];
        }
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};