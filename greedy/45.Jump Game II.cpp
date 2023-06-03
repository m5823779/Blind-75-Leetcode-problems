class Solution {
public:
    int jump(vector<int>& nums) {
        // method 1: brute force (recursive)
        return solve(nums, 0);        
    }
private:
    int solve(vector<int>& nums, int cur) {
        if (cur >= nums.size() - 1) {
            return 0;
        }
        int result = INT_MAX;
        for (int i = 1; i <= nums[cur]; i++) {
            int tmp = solve(nums, cur + i);
            if (tmp != INT_MAX) {
                result = min(result, 1 + tmp);
            }
        }
        return result;
    }
    // time complexity: O(m ^ n)  m: average step / n: array length
    // space complexity: O(n)
};


class Solution {
public:
    int jump(vector<int>& nums) {
        // method 1: brute force (recursive + memorization)
        memo = vector<int>(nums.size(), -1);
        return solve(nums, 0);        
    }

private:
    vector<int> memo;
    int solve(vector<int>& nums, int cur) {
        if (cur >= nums.size() - 1) {
            return 0;
        }
        if (memo[cur] != -1) return memo[cur];

        int result = INT_MAX;
        for (int i = 1; i <= nums[cur]; i++) {
            int tmp = solve(nums, cur + i);
            if (tmp != INT_MAX) {
                result = min(result, 1 + tmp);
            }
        }
        return memo[cur] = result;
    }
    // time complexity: O(m ^ n)  m: average step / n: array length
    // space complexity: O(n)
};


class Solution {
public:
    int jump(vector<int>& nums) {
        // method 2: dynamic programming
        const int n = nums.size();
        vector<int> dp(n, n + 1);
        dp[n - 1] = 0;
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n) {
                    dp[i] = min(dp[i], 1 + dp[i + j]);
                }
            }
        }
        return dp[0] >= n + 1 ? -1 : dp[0]; 
    }
    // time complexity: O(m ^ n)  m: average step / n: array length
    // space complexity: O(n)
};


class Solution {
public:
    int jump(vector<int>& nums) {
        // method 3: two pointer (greedy)
        int level = 0;
        int l = 0;
        int r = 0;
        while (r < nums.size() - 1) {
            level++;

            int farest = r;
            for (int i = l; i <= r; i++) {
                farest = max(farest, i + nums[i]);
            }

            l = r + 1;
            r = farest;
        }
        return level;
    }
    // time complexity: O(n)
    // space compleixty: O(1)
};


