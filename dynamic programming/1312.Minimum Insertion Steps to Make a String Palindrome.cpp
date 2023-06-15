class Solution {
public:
    int minInsertions(string s) {
        // method 1: Dynamic programming
        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
    // time complexity: O(n^2 / 2)
    // space complexity: O(n^2)
};


class Solution {
public:
    int minInsertions(string s) {
        // method 2: dynamic programming
        string s_rev(s.rbegin(), s.rend());
        return s.size() - lcs(s, s_rev);
    }
private:
    int lcs(string a, string b) {
        const int m = a.size();
        const int n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (a[i] == b[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
    // time complexity: O(n^2)
    // space complexity: O(n^2)
};