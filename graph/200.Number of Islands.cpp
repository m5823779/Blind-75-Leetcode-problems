class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // method 1: DFS (Depth first search)
        // 1. enumerate graph <i, j> pair
        // 2. if node [i, j] is land (1), answer +1
        // 3. access all neighbor using DFS, BFS. Until reach boundry, or node is water (0)
        // 4. mark visited node to 0
        
        if (grid.empty()) return 0;
        
        int nums_of_islands = 0;
        m = grid.size();
        n = grid[0].size();
        
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == '1') {
                    nums_of_islands++;
                    dfs(grid, x, y);
                }
            }
        }
        return nums_of_islands;
    }
private:
    int m, n;
    
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n) return;
        if (grid[x][y] == '0') return;
        
        grid[x][y] = '0';
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    // time complexity: O(mn)
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // method 2: BFS (breadth first search)
        // 1. enumerate graph <i, j> pair
        // 2. if node [i, j] is land (1), answer +1
        // 3. access all neighbor using DFS, BFS. Until reach boundry, or node is water (0)
        // 4. mark visited node to 0

        int ans = 0;
        const int m = grid.size();
        const int n = grid[0].size();

        int offset[] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> todo;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = '0';
                    todo.push({i, j});

                    while(!todo.empty()) {
                        pair<int, int> tmp = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; ++k) {
                            int _i = tmp.first + offset[k];
                            int _j = tmp.second + offset[k + 1];
                            if (_i < 0 || _j < 0 || _i >= m || _j >= n) continue;
                            if (grid[_i][_j] == '0') continue;

                            grid[_i][_j] = '0';
                            todo.push({_i, _j});
                        }
                        
                    }
                }
            }
        }
        return ans;
    }
    // time complexity: O(mn)
};