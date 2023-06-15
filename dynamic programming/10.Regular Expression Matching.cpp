class Solution {
public:
    bool isMatch(string s, string p) {
        // method 1: brute force (recursion)
        m = s.size();
        n = p.size();
        return dfs(s, 0, p, 0);
    }
private:
    int m, n;
    bool dfs(string s, int i, string p, int j) {
        if (i >= m && j >= n) return true;
        if (j >= n) return false;
        
        // next pattern is *
        if (j + 1 < n && p[j + 1] == '*') {
            // dont use pattern * (ignore previous char)
            if (dfs(s, i, p, j + 2)) return true; 
            // use pattern *
            if ((i + 1 <= m && (s[i] == p[j] || p[j] == '.')) && dfs(s, i + 1, p, j)) return true;
        }
        else {
            if (i + 1 <= m && (s[i] == p[j] || p[j] == '.')) return dfs(s, i + 1, p, j + 1);
        }
        return false;
    }
    // time complexity: O(2^len(s))
    // space complexity: O(len(s))
};


class Solution {
public:
    bool isMatch(string s, string p) {
        // method 2: recusion + memorization
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
        
        bool match = i + 1 <= m && (s[i] == p[j] || p[j] == '.');
        // next pattern is *
        if (j + 1 < n && p[j + 1] == '*') {
            if (dfs(s, i, p, j + 2) ||  // dont use pattern * (ignore previous char)
            match && dfs(s, i + 1, p, j)) return true;  // use pattern *
        }

        if (match) return memo[i][j] = dfs(s, i + 1, p, j + 1);
        return memo[i][j] = false;
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};


class Solution {
public:
    bool isMatch(string s, string p) {
        // method 3: dynamic programming 
        const int m = s.size();
        const int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[m][n] = true;
        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                bool match = i + 1 <= m && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < n && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
                }
                else {
                    dp[i][j] = match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
    // time complexity: O(mn)
    // spacec complexity: O(mn)
};