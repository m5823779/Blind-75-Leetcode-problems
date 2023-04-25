class NumMatrix {
private:
    vector<vector<int>> m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // method 1: brute force
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            for (int j = col1; j <= col2; j++) {
                sum += m[i][j];
            }
        }
        return sum;
    }
    // time complexity: O(10^4 * m * n)
    // space compleixty: O(1)
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */


class NumMatrix {
private:
    int m, n;
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        // method 2: prefix sum
        m = matrix.size();
        n = matrix[0].size();
        sum = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = matrix[i][j] + 
                            (i - 1 >= 0 ? sum[i - 1][j] : 0) + 
                            (j - 1 >= 0 ? sum[i][j - 1] : 0) -
                            (i - 1 >= 0 && j - 1 >= 0 ? sum[i - 1][j - 1] : 0);
            }
        }
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2][col2] - 
               (row1 - 1 >= 0 ? sum[row1 - 1][col2] : 0) -
               (col1 - 1 >= 0 ? sum[row2][col1 - 1] : 0) + 
               (row1 - 1 >= 0 && col1 - 1 >= 0 ? sum[row1 - 1][col1 - 1] : 0);
    }
    // time complexity: O(1)
    // space complexity: O(1)
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */