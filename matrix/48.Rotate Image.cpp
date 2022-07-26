class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // method 1: pointer
        int l = 0;
        int t = l;
        
        int r = matrix[0].size() - 1;
        int b = r;

        while (l < r) {
            for (int i = 0; i < r - l; ++i) {
                // store left-top to tmp
                int tmp = matrix[t][l + i];
                
                // move left-bottom to left-top
                matrix[t][l + i] = matrix[b - i][l];
                
                // move right-bottom to left-bottom
                matrix[b - i][l] = matrix[b][r - i];
                    
                // move right-top to right-bottom
                matrix[b][r - i] = matrix[t + i][r];
                    
                // move left-top to right-top
                matrix[t + i][r] = tmp;
            }
            l += 1;
            r -= 1;
            
            t += 1;
            b -= 1;
        }
        // time complexity: O(n^2)
        // space complexity: O(1)
    }
};