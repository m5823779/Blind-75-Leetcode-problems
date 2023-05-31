class Solution {
public:
    int fib(int n) {
        // method 1: recursion
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
    // time complexity: O(2^n)
    // space complexity: O(n)
};


class Solution {
public:
    int fib(int n) {
        // method 2: recursion + memorization
        memo = vector<int>(n + 1, -1);
        return dfs(n);
    }
private:
    vector<int> memo;
    int dfs(int n) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = dfs(n - 1) + dfs(n - 2);
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    int fib(int n) {
        // method 3: dynamic programming
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    // time complexity: O(n)
    // space complexity: O(n)
};