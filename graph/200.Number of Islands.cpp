class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // method 1: DFS (Depth first search)
        // 1. enumerate all elements
        // 2. if is land (1), check its neighbors (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)
        // 3. if is water (0) or out of boundry, stop
        // 4. mark visited node
        
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
        if (grid[x][y] == '0' || grid[x][y] == '2') return;
        
        grid[x][y] = '2';
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};