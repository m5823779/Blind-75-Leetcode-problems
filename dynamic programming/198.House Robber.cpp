class Solution {
public:
    int rob(vector<int>& nums) {
        // method 1: brute force (recursion / pick not pick approach)
        return solve(nums, 0);
    }
private:
    int solve(vector<int>& nums, int current) {
        if (current >= nums.size()) return 0;
        return max(nums[current] + solve(nums, current + 2), solve(nums, current + 1));
    }
    // time complexity: O(2^n)
    // space complexity: O(n)
};


class Solution {
public:
    int rob(vector<int>& nums) {
        // method 2: recursion + memorize (bottom - up)
        // m[i] = max(rob[i - 2] + nums[i], rob[i - 1])

        const int n = nums.size();
        m = vector<int>(n, -1);
        return rob(nums, n - 1);
    }
private:
    vector<int> m;
    int rob(vector<int>& nums, int i) {
        if(i < 0) return 0;
        if(m[i] != -1) return m[i];
        return m[i] = max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    int rob(vector<int>& nums) {
        // method 2: recursion + memorize (top - bottom
        const int n = nums.size();
        memo = vector(n, -1);
        return solve(nums, 0);
    }
private:
    vector<int> memo;
    int solve(vector<int>& nums, int current) {
        if (current >= nums.size()) return 0;
        if (memo[current] != -1) return memo[current];
        return memo[current] = max(nums[current] + solve(nums, current + 2), solve(nums, current + 1));
    }
    // time complexity: O(n)
    // space complexity: O(n)
};

class Solution {
public:
    int rob(vector<int>& nums) {
        // method 1: dynamic programming
        // 1. create vector "dp" to store previous max result
        // 2. enumerate nums[i], such that dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        const int n = nums.size();
        
        vector<int> dp(n, 0);
        
        for (int i = 0; i < n; ++i) {
            dp[i] = max( (i >= 2 ? dp[i - 2]: 0) + nums[i], 
                         (i >= 1 ? dp[i - 1]: 0) );
        }
        
        return dp.back();
        // time complexity: O(n)
        // space complexity: O(n)
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        // method 1: dynamic programming (optimize)
        // 1. dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]), because current element only influences by i - 1 & i - 2
        // 2. use two tmp element "rob1" & "rob2" to replace memory        
        int rob1 = 0;
        int rob2 = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = tmp;  
        }
        
        return rob2;
        // time complexity: O(n)
        // space complexity: O(1)
    }
};


