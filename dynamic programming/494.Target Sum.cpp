class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // method 1: recursion + memorization
        vector<unordered_map<int, int>> memo(nums.size());
        return dfs(nums, 0, target, 0, memo);
    }
private:
    int dfs(vector<int>& nums, int cur, int target, int sum, vector<unordered_map<int, int>>& memo) {
        if (cur >= nums.size()) return sum == target;
        if (memo[cur].find(sum) != memo[cur].end()) return memo[cur][sum];
        return memo[cur][sum] = dfs(nums, cur + 1, target, sum + nums[cur], memo) + dfs(nums, cur + 1, target, sum - nums[cur], memo);
    }
    // time complexity: O(2^n) -> O(n * target)
    // space compleixty: O(n * target)
};