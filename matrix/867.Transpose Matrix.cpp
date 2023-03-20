class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> tran(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tran[j][i] = matrix[i][j];
            }
        }
        return tran;
    }
    // time complexity: O(m * n)
    // space complexity: O(m * n)
};