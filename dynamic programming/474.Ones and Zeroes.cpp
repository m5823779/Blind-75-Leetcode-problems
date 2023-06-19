class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // method 1: brute force (recursion)
        return dfs(strs, 0, 0, 0, m, n);
    }
private:
    vector<vector<vector<int>>> memo;
    int dfs(vector<string>& strs, int cur, int i, int j, int m, int n) {
        if (i > m || j > n) return 0;
        if (cur >= strs.size()) return 0;

        int _i = counter(strs[cur]).first;
        int _j = counter(strs[cur]).second;

        int res = dfs(strs, cur + 1, i, j, m, n);
        if (i + _i <= m && j + _j <= n) {
            res = max(res, 1 + dfs(strs, cur + 1, i + _i, j + _j, m, n));
        }
        return res;
    }

    pair<int, int> counter (string s) {
        int zeros = 0;
        int ones = 0;
        for (char c : s) {
            if (c == '0') zeros++;
            else ones++;
        }
        return {zeros, ones};
    }
    // time complexity: O(2^n)
    // space compleixt: O(n)
};


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // method 2: brute force (recursion + memorization)
        memset(memo, -1, sizeof(memo));
        return dfs(strs, 0, 0, 0, m, n);
    }
private:
    int memo[601][101][101];
    int dfs(vector<string>& strs, int cur, int i, int j, int m, int n) {
        if (i > m || j > n) return 0;
        if (cur >= strs.size()) return 0;
        if (memo[cur][i][j] != -1) return memo[cur][i][j];

        int _i = counter(strs[cur]).first;
        int _j = counter(strs[cur]).second;

        int res = dfs(strs, cur + 1, i, j, m, n);
        if (i + _i <= m && j + _j <= n) {
            res = max(res, 1 + dfs(strs, cur + 1, i + _i, j + _j, m, n));
        }
        return memo[cur][i][j] = res;
    }

    pair<int, int> counter (string s) {
        int zeros = 0;
        int ones = 0;
        for (char c : s) {
            if (c == '0') zeros++;
            else ones++;
        }
        return {zeros, ones};
    }
};