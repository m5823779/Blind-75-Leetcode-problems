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