class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        // meethod 1: LCS
        const int m = arr.size();
        const int n = target.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (arr[i] == target[j]) {
                    dp[i][j] = 1 + (i + 1 < m && j + 1 < n ? dp[i + 1][j + 1] : 0);
                }
                else {
                    dp[i][j] = max(i + 1 < m ? dp[i + 1][j] : 0, j + 1 < n ? dp[i][j + 1] : 0);
                }
            }
        }
        return target.size() - dp[0][0];
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};


class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        // method 2: LIS
        const int n = target.size();
        const int m = arr.size();
        
        unordered_map<int, int> old2new;
        for (int i = 0; i < n; i++) {
            old2new[target[i]] = i;
        }

        // lis
        vector<int> lis;
        for (int i = 0; i < m; i++) {
            if (old2new.find(arr[i]) == old2new.end()) continue;
            int key = old2new[arr[i]];
            auto index = lower_bound(lis.begin(), lis.end(), key);
            if (index == lis.end()) lis.push_back(key);
            else *index = key;
        }
        return n - lis.size();
    }
    // time complexity: O(n + mlogm)
    // space complexity: O(m)
};