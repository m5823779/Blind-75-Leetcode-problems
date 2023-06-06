class Solution {
public:
    int minDistance(string word1, string word2) {
        // method 1: brute force
        m = word1.size();
        n = word2.size();
        return dfs(word1, 0, word2, 0);
    }
private:
    int m, n;
    int dfs(string s1, int i, string s2, int j) {
        if (i == m && j == n) return 0;
        if (i == m) return 1 + dfs(s1, i, s2, j + 1);
        if (j == n) return 1 + dfs(s1, i + 1, s2, j);

        if (s1[i] == s2[j]) return dfs(s1, i + 1, s2, j + 1);
        else {
            return 1 + min({dfs(s1, i + 1, s2, j), dfs(s1, i, s2, j + 1), dfs(s1, i + 1, s2, j + 1)});
        }
    }
    // time complexity: O(3^max(m, n))
    // space complexity: O(max(m, n))
};


class Solution {
public:
    int minDistance(string word1, string word2) {
        // method 2: recucrsion + memorization
        m = word1.size();
        n = word2.size();
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return dfs(word1, 0, word2, 0);
    }
private:
    int m, n;
    vector<vector<int>> memo;
    int dfs(string s1, int i, string s2, int j) {
        if (i == m && j == n) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (i == m) return memo[i][j] = 1 + dfs(s1, i, s2, j + 1);
        if (j == n) return memo[i][j] = 1 + dfs(s1, i + 1, s2, j);
        
        if (s1[i] == s2[j]) return memo[i][j] = dfs(s1, i + 1, s2, j + 1);
        else {
            return memo[i][j] = 1 + min({dfs(s1, i + 1, s2, j), dfs(s1, i, s2, j + 1), dfs(s1, i + 1, s2, j + 1)});
        }
    }
};


class Solution {
public:
    int minDistance(string word1, string word2) {
        // method 3: dynamic programming
        const int m = word1.size();
        const int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) dp[i][n] = m - i;
        for (int j = n - 1; j >= 0; j--) dp[m][j] = n - j;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) dp[i][j] = dp[i + 1][j + 1];
                else dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
            }
        }
        return dp[0][0];
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};