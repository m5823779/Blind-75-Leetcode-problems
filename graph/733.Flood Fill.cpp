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


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // method: BFS
        int org_color = image[sr][sc];
        if (org_color == color) return image;
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        int dir[] = {0, 1, 0, -1, 0};

        q.push({sr, sc});
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int _i = i + dir[d];
                int _j = j + dir[d + 1];
                if (_i < 0 || _j < 0 || _i >= image.size() || _j >= image[0].size() || image[_i][_j] != org_color) continue;
                image[_i][_j] = color;
                q.push({_i, _j});
            }
        }
        return image;
    }
};