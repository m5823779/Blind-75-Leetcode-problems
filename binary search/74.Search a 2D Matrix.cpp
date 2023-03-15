class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // method: binary search
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            int e = matrix[mid / n][mid % n];
            if (e == target) {
                return true;
            }
            if(e > target){
                r = mid - 1;
            }
            else { 
                l = mid + 1;
            }
        }
        return false;
    }
    // time complexity: O(log(m * n))
    // space complexity: O(1)
};