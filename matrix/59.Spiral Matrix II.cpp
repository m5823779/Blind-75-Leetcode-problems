class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int l = 0;
        int r = n - 1;
        int t = 0;
        int b = n - 1;

        int i = 1;
        while (l <= r && t <= b) {
            // left -> right
            for (int x = l; x <= r; x++) {
                ans[t][x] = i;
                i++;
            }
            t += 1;

            // top -> bottom
            for (int y = t; y <=b; y++) {
                ans[y][r] = i;
                i++;
            }
            r -= 1;

            // right -> left
            for (int x = r; x>= l; x--) {
                ans[b][x] = i;
                i++;
            }
            b -= 1;

            // bottom -> top
            for (int y = b; y >= t; y--) {
                ans[y][l] = i;
                i++;
            }
            l += 1;
        }
        return ans;
    }
};