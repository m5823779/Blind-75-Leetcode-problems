class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // method: DFS
        int max_area = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int sub_area = dfs(grid, i, j);
                    max_area = max(max_area, sub_area);
                }
            }
        }
        return max_area;
    }
private:
    int m, n;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0;
        }
        if (grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // method: BFS
        int max_area = 0;
        const int m = grid.size();
        const int n = grid[0].size();
        
        int dir[5] = {0, 1, 0, -1, 0};

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (grid[i][j] == 1) {
                    int sub_area = 1;
                    grid[i][j] = 0;
                    q.push({i, j});

                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int _i = p.first + dir[k];
                            int _j = p.second + dir[k + 1];
                            if (_i < 0 || _j < 0 || _i >= m || _j >= n) continue;
                            if (grid[_i][_j] == 1) {
                                sub_area += 1;
                                grid[_i][_j] = 0;
                                q.push({_i, _j});
                            }
                        }
                    }
                    max_area = max(max_area, sub_area);
                }
            }
        }
        return max_area;
    }
};