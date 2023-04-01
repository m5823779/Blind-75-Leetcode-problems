class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // method: BFS
        // array for rolling up, down, left, right 
        int direction[5] = {0, 1, 0, -1, 0};

        // get maze size
        int m = maze.size();
        int n = maze[0].size();
        
        // starting point
        int i0 = start[0];
        int j0 = start[1];

        // record vertex visited or not
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[i0][j0] = true;

        // queue for bfs, store coordinate (i, j)
        queue<pair<int, int>> q;
        q.push({i0, j0});

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            // rolling up, down, left, right 
            for (int d = 0; d < 4; d++) {
                int i = p.first;
                int j = p.second;

                // move forward until out of boundary or hit the wall
                while (i + direction[d] >= 0 && j + direction[d + 1] >= 0 && i + direction[d] < m && j + direction[d + 1] < n && 
                       maze[i + direction[d]][j + direction[d + 1]] == 0) {
                    i += direction[d];
                    j += direction[d + 1];
                }

                // return if reach the target
                if (i == destination[0] && j == destination[1]) {
                    return true;
                }

                // pass if already visited the vertex
                if (visited[i][j]) {
                    continue;
                }
                visited[i][j] = true;
                
                q.push({i, j});
            }
        }
        return false;
    }    
    // time complexity: O(mn)
    // space complexity: O(mn)
};


class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // method: DFS
        m = maze.size();
        n = maze[0].size();

        target_i = destination[0];
        target_j = destination[1];

        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        return dfs(maze, start[0], start[1]);
    }

private:
    int m;
    int n;
    int target_i;
    int target_j;
    
    vector<vector<bool>> visited;
    vector<int> direction = {0, 1, 0, -1, 0};

    bool dfs(vector<vector<int>>& maze, int i, int j) {
        if (i == target_i && j == target_j) {
            return true;
        }
        if (visited[i][j]) {
            return false;
        }
        visited[i][j] = true;

        for (int d = 0; d < 4; d++) {
            int _i = i;
            int _j = j;
            while (_i + direction[d] >= 0 && _j + direction[d + 1] >= 0 && _i + direction[d] < m && _j + direction[d + 1] < n && 
                   maze[_i + direction[d]][_j + direction[d + 1]] == 0) {
                       _i += direction[d];
                       _j += direction[d + 1];
            }
            if (dfs(maze, _i, _j)) {
                return true;
            }
        }
        return false;
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};
