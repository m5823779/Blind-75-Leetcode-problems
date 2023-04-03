class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        org_color = image[sr][sc];
        if (org_color == color) {
            return image;
        }
        else {
            dfs(image, sr, sc, color);
            return image;
        }
    }
private:
    int org_color;
    int m, n;
    void dfs(vector<vector<int>>& image, int i, int j, int new_color) {
        if (i < 0 || j < 0 || i>= m || j >= n) {
            return;
        }
        if (image[i][j] != org_color) {
            return;
        }
        image[i][j] = new_color;
        dfs(image, i + 1, j, new_color);
        dfs(image, i - 1, j, new_color);
        dfs(image, i, j + 1, new_color);
        dfs(image, i, j - 1, new_color);
    }
    // time complexity: O(mn)
    // space complexity: O(1)
};