class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // method: pointer
        vector<int> ans;
        
        int l = 0;
        int r = matrix[0].size();
        
        int t = 0;
        int b = matrix.size();
        
        while (l < r && t < b) {
            // left -> right
            for (int i = l; i < r; ++i) ans.push_back(matrix[l][i]);
            t += 1;
            
            // top -> bottom
            for (int i = t; i < b; ++i) ans.push_back(matrix[i][r - 1]);
            r -= 1;
            
            if ((l < r && t < b) == false) break;
                
            // right -> left
            for (int i = r - 1; i > l - 1; --i) ans.push_back(matrix[b - 1][i]);
            b -= 1;
            
            // bottom - > top
            for (int i = b - 1; i > t - 1; --i) ans.push_back(matrix[i][l]);
            l += 1;
        }
        return ans;
    }
    // time complexity: O(mn)
    // space complexity: O(1)
};