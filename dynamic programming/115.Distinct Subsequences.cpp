class Solution {
public:
    int numDistinct(string s, string t) {
        // method 1: recursion + memorization
        m = s.size();
        n = t.size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dfs(s, 0, t, 0);
    }
private:
    int m, n;
    vector<vector<int>> memo;
    int dfs(string s, int i, string t, int j) {
        if (j == n) return 1;
        if (i == m) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] != t[j]) return memo[i][j] = dfs(s, i + 1, t, j);
        else return memo[i][j] = dfs(s, i + 1, t, j + 1) + dfs(s, i + 1, t, j);
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};


class Solution {
public:
    int numDistinct(string s, string t) {
        // method 2: Dynamic programming
        const int m = s.size();
        const int n = t.size();
        vector<vector<uint>> dp(m + 1, vector<uint>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                else dp[i][j] = dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};