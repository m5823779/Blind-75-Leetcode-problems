class Solution {
public:
    bool isMatch(string s, string p) {
        // method 1: brute force
        m = s.size();
        n = p.size();
        return dfs(s, 0, p, 0);
    }
private:
    int m, n;
    bool dfs(string s, int i, string p, int j) {
        if (i >= m && j >= n) return true;
        if (j >= n) return false;
        if (p[j] == '*') {
            if (dfs(s, i, p, j + 1) || (i + 1 <= m && dfs(s, i + 1, p, j))) return true;
        }
        else if (p[j] == '?' || s[i] == p[j]) {
            return i + 1 <= m && dfs(s, i + 1, p, j + 1);
        }
        return false;
    }
    // time complexity: O(2^m)
    // space compleixty: O(m)
};


class Solution {
public:
    bool isMatch(string s, string p) {
        // method 2: recursion + memorization
        m = s.size();
        n = p.size();
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return dfs(s, 0, p, 0);
    }
private:
    int m, n;
    vector<vector<int>> memo;
    bool dfs(string s, int i, string p, int j) {
        if (i >= m && j >= n) return true;
        if (j >= n) return false;
        if (memo[i][j] != -1) return memo[i][j];

        if (p[j] == '*') {
            if (dfs(s, i, p, j + 1) || (i + 1 <= m && dfs(s, i + 1, p, j))) return memo[i][j] = true;
        }
        if (p[j] == '?' || s[i] == p[j]) {
            return memo[i][j] = i + 1 <= m && dfs(s, i + 1, p, j + 1);
        }
        return memo[i][j] = false;
    }
    // time complexity: O(mn)
    // space compleixty: O(mn)
};


class Solution {
public:
    bool isMatch(string s, string p) {
        // method 3: Dynamic programming
        const int m = s.size();
        const int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (p[j] == '*') {
                    dp[i][j] = dp[i][j + 1] || (i + 1 <= m && dp[i + 1][j]);
                }
                if (p[j] == '?' || s[i] == p[j]) {
                    dp[i][j] = i + 1 <= m && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};