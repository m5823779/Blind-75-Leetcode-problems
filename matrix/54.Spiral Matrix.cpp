class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // method: pointer
        vector<int> ans;

        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // top - bottom
            for (int j = top; j <= bottom; j++) {
                ans.push_back(matrix[j][right]);
            }
            right--;

            if (left > right || top > bottom) break;

            // right - left
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;

            // bottom - top
            for (int j = bottom; j >= top; j--) {
                ans.push_back(matrix[j][left]);
            }
            left++;
        }
        return ans;
    }
    // time complexity: O(mn)
    // space complexity: O(1)
};