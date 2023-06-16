class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // method 1: dynamic programming
        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
    // time complexity: O(n^2 / 2)
    // space complexity: O(n^2)
};