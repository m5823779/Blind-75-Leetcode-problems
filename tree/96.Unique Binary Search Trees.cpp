class Solution {
public:
    int numTrees(int n) {
        // method: dynamic programming
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int root_id = 0; root_id < i; root_id++) {
                int left_subtree = dp[root_id];
                int right_subtree = dp[i - 1 - root_id];
                dp[i] += left_subtree * right_subtree;
            }
        }
        return dp[n];
    }
    // time complexity: O(n^2)
    // space complexity: O(n)
};