class Solution {
public:
    int uniquePaths(int m, int n) {
        // method 1: brute force (recursion)
        return solve(m - 1, n - 1);
    }
private:
    int solve(int m, int n) {
        if (m == 0 && n ==0) return 1;
        if (m < 0 || n < 0) return 0;
        return solve(m - 1, n) + solve(m, n - 1);
    }
    // time complexity: O(2^mn)
    // space complexity: O(m or n) which is bigger
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        // method 2: brute force (recursion + memorization)
        visited = vector<vector<int>>(m, vector<int>(n, -1));
        return solve(m - 1, n - 1);
    }
private:
    vector<vector<int>> visited;

    int solve(int m, int n) {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;
        if (visited[m][n] != -1) return visited[m][n];
        return visited[m][n] = solve(m - 1, n) + solve(m, n - 1);
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        // method 2: brute force (recursion + memorization)
        visited = vector<vector<int>>(m, vector<int>(n, -1));
        target_x = m - 1;
        target_y = n - 1;
        return solve(0, 0);
    }
private:
    vector<vector<int>> visited;
    int target_x;
    int target_y;

    int solve(int cur_x, int cur_y) {
        if (cur_x == target_x && cur_y == target_y) return 1;
        if (cur_x > target_x || cur_y > target_y) return 0;
        if (visited[cur_x][cur_y] != -1) return visited[cur_x][cur_y];
        return visited[cur_x][cur_y] = solve(cur_x + 1, cur_y) + solve(cur_x, cur_y + 1);
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        //method 3: dynamic programming (bottom-up approach)
        // 1. create 2D DP array to store how many unique path if start from <i, j>
        // 2. setting basic case (dp[m - 1][n - 1] = 1, if start from <m - 1, n - 1> there have one path to target)
        // 3. enumerate grid to filling to DP array dp[i][j] = dp[i + 1][j] + dp[i][j + 1]
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] += (i + 1 >= m ? 0 : dp[i + 1][j]) + (j + 1 >= n ? 0 : dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};