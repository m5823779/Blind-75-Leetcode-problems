class Solution {
    // method 1: brute force (recursion)
public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, 0, text2, 0);
    }
private:
    int solve(string text1, int ptr1, string text2, int ptr2) {
        if (ptr1 >= text1.size() || ptr2 >= text2.size()) return 0;
        if (text1[ptr1] == text2[ptr2]) return 1 + solve(text1, ptr1 + 1, text2, ptr2 + 1);
        return max(solve(text1, ptr1 + 1, text2, ptr2), solve(text1, ptr1, text2, ptr2 + 1));
    }
    // time complexity: O(2^n)
    // space complexity: O(n) shortest string's length
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //     a c e
        //   0 0 0 0    
        // a 0 1 
        // b 0   1 1  
        // c 0   2   
        // d 0     2  
        // e 0     3  
        //   
        // method: dynamic programming
        // 1. create m x n 2d vecctor "LCS" which m = text1.size() + 1, n = text2.size() + 1, and initialize all element as 0 
        // 2. enumerate <i, j> pairs, which i [1, text1.size()] and j [1, text2.size()]
        // 3. if text1[i - 1] == text2[j - 1] -> LCS[i][j] = 1 + LCS[i - 1][j - 1]
        // 4. else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1])
        // 5. return LCS[text1.size()][text2.size()]
        
        const int col = text2.size() + 1;
        const int row = text1.size() + 1;
        
        vector<int> v(col, 0);
        vector<vector<int>> LCS(row, v);
        
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (text1[i - 1] == text2[j - 1]) LCS[i][j] = 1 + LCS[i - 1][j - 1];
                else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
        return LCS[text1.size()][text2.size()];
        
        // time complexity: O(m * n)
        // space complexity: O(m * n)
    } 
};


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //    a c e
        // a  3     0
        // b    2 1 0 
        // c    2   0
        // d      1 0 
        // e      1 0 
        //    0 0 0 0
        // method: dynamic programming
        const int m = text1.size();
        const int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
    // time complexity: O(m * n)
    // space complexity: O(m * n)
};