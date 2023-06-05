class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // method 1: brute force
        l1 = s1.size();
        l2 = s2.size();
        l3 = s3.size();
        return dfs(s1, 0, s2, 0, s3, 0);
    }
private:
    int l1, l2, l3;
    bool dfs(string s1, int i, string s2, int j, string s3, int k) {
        if (i >= l1 && j >= l2 && k >= l3) return true;
        if (s3[k] == s1[i]) {
            if (dfs(s1, i + 1, s2, j, s3, k + 1)) return true;
        }
        if (s3[k] == s2[j]) {
            if (dfs(s1, i, s2, j + 1, s3, k + 1)) return true;
        }
        return false;
    }
    // time complexity: O(2^n)
    // space complexity: O(n)
};


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // method 2: recursion + memorization
        l1 = s1.size();
        l2 = s2.size();
        l3 = s3.size();
        memo = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
        return dfs(s1, 0, s2, 0, s3, 0);
    }
private:
    int l1, l2, l3;
    vector<vector<int>> memo;
    bool dfs(string s1, int i, string s2, int j, string s3, int k) {
        if (i == l1) return memo[i][j] = s2.substr(j) == s3.substr(k);
        if (j == l2) return memo[i][j] = s1.substr(i) == s3.substr(k);
        if (memo[i][j] != -1) return memo[i][j];
        if ((s3[k] == s1[i] && dfs(s1, i + 1, s2, j, s3, k + 1)) || (s3[k] == s2[j] && dfs(s1, i, s2, j + 1, s3, k + 1))) return true;
        return memo[i][j] = false;
    }
    // time complexity: O(m * n)
    // space complexity: O(m * n)
};


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // method 3: dynamic programming 
        const int m = s1.size();
        const int n = s2.size();
        if (m + n != s3.size()) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i < m && s1[i] == s3[i + j] && dp[i + 1][j]) dp[i][j] = true;
                if (j < n && s2[j] == s3[i + j] && dp[i][j + 1]) dp[i][j] = true;
            }
        }
        return dp[0][0];
    }
};