class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // method 1: brute force-DFS (depth first search)
        // 1. enumerate 2D array
        // 2. depth first search its neighbor (north, south, east, and west)
        //      - if x or y < 0 -> pacific ocean -> return 1
        //      - if x >= n or y >= m -> atlantic ocean -> return 2
        //      - if previous node lower than current node -> return 0
        //      - before visit neighbor, set current height to max value to avoid access into node which have same heigh
        // 3. if (north | south | east | west) = 3 append to answer
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < heights.size(); ++i)
            for (int j = 0; j < heights[i].size(); ++j)
                if (dfs(heights, i, j, heights[i][j]) >= 3) ans.push_back({i, j});

        return ans;
    }
    
private:
    int dfs(vector<vector<int>>& heights, int x, int y, int height) { 
        if (x < 0 || y < 0) return 1;
        if (x >= heights.size() || y >= heights[0].size()) return 2;
        if (heights[x][y] > height) return 0;
        height = heights[x][y];
        
        heights[x][y] = INT_MAX;
        int valid = dfs(heights, x-1, y, height) |
                    dfs(heights, x+1, y, height) | 
                    dfs(heights, x, y-1, height) | 
                    dfs(heights, x, y+1, height);
        
        heights[x][y] = height;
        return valid;
    }
    // time complexity: O((mn)^2) for each cell enumerate m x n times
};


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // method 2: DFS (depth first search)
        // 1. create two 2D array (pacific & atlantic) to store which cell can board ocean
        // 2. enumerate first rows / columns elements & enumerate last rows / columns
        // 3. DFS for north, south, east, and west
        //      - if out of boundry, return 
        //      - if previous node lower than current node, return
        // 4. enumerate both 2D array which created in step 1, if both true, append to ans
        
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            dfs(heights, i, 0, heights[i][0], pacific);  // first columns
            dfs(heights, i, n - 1, heights[i][n-1], atlantic);  // last columns
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(heights, 0, j, heights[0][j], pacific);  // first rows
            dfs(heights, m - 1, j, heights[m-1][j], atlantic);  // last rows
        }
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) 
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
        return ans;
    }
    
private:
    int m, n;
    
    void dfs(vector<vector<int>>& graph, int x, int y, int height, vector<vector<bool>>& visited) {
        if (x < 0 || y < 0 || x >= m || y >= n) return;
        if (visited[x][y] || graph[x][y] < height) return;
        
        visited[x][y] = true;
        height = graph[x][y];
        
        dfs(graph, x+1, y, height, visited);
        dfs(graph, x-1, y, height, visited);
        dfs(graph, x, y+1, height, visited);
        dfs(graph, x, y-1, height, visited);
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // method 3: BFS (breadth first search)
        // 1. create two 2D array (pacific & atlantic) to store which cell can board ocean
        // 2. enumerate first rows / columns elements & enumerate last rows / columns
        // 3. BFS for north, south, east, and west
        //      - if out of boundry, return 
        //      - if previous node lower than current node, return
        // 4. enumerate both 2D array which created in step 1, if both true, append to ans
        
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            qp.push({i, 0});  // first columns
            qa.push({i, n - 1});  // last columns
        }
        
        for (int j = 0; j < n; ++j) {
            qp.push({0, j});  // first rows
            qa.push({m - 1, j});  // last rows
        }
        
        bfs(heights, qp, pacific);
        bfs(heights, qa, atlantic);
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) 
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
        return ans;
    }
    
private:
    int m, n;
    const vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> qp;
    queue<pair<int, int>> qa;
    int h;
    
    void bfs(vector<vector<int>>& graph, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {        
        while(!q.empty()) {
            const int x = q.front().first;
            const int y = q.front().second;
            q.pop();
            
            h = graph[x][y];
            visited[x][y] = true;

            for (int i = 0; i < 4; ++i) {
                int tx = x + dirs[i];
                int ty = y + dirs[i + 1];
                if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
                if (h > graph[tx][ty])  continue;
                if (visited[tx][ty]) continue;
                q.push({tx, ty});
            }
        }
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};