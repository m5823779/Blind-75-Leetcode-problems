class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // method : hash table
        // 1. create hash table "zero_rows" & "zero_colums" to store which row and column need set to 0
        // 2. enumerate <i, j>
        // 3. zero_rows[j] = Ture, zero_colums[i] = True, if matrix[i][j] == 0
        // 4. enumerate <i, j>
        // 5. matrix[i][j] == 0, if zero_rows[j] = Ture || zero_colums[i] = True
        
        const int height = matrix.size();
        const int width = matrix[0].size();
        
        vector<bool> zero_rows(height, false);
        vector<bool> zero_columns(width, false);
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == 0) {
                    zero_rows[i] = true;
                    zero_columns[j] = true;
                }
            }
        }
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (zero_rows[i] || zero_columns[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    // time complexity: O(mn)
    // space complexity: O(m + n)
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // method : hash table (optimize)
        
        const int height = matrix.size();
        const int width = matrix[0].size();
        bool zero_row = false;
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    
                    if (i > 0) matrix[i][0] = 0;
                    else zero_row = true;
                }
            }
        }
        
        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        
        if (matrix[0][0] == 0) {
            for (int i = 0; i < height; ++i) {
                matrix[i][0] = 0;
            }
        }
        
        if (zero_row) {
            for (int j = 0; j < width; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
    // time complexity: O(mn)
    // space complexity: O(1)
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) firstRowZero = true;
                    if (j == 0) firstColZero = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowZero) {
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        }

        if (firstColZero) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};