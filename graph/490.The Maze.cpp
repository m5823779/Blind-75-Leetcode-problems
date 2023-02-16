class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // method 1: BFS
        dir = vector<vector<int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

        m = maze.size();
        n = maze[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = 1;

        while(!q.empty()) {
            int x0 = q.front().first;
            int y0 = q.front().second;
            q.pop();

            for (int i = 0; i < dir.size(); i++) {
                auto [x, y] = nextStep(maze, x0, y0, i);
                if (x == destination[0] && y == destination[1]) { 
                    return true;
                }
                if (visited[x][y] == 1) {
                    continue;
                }
                visited[x][y] = 1;
                q.push({x, y});
            }
        }
        return false;
    }

private:
    int m, n;
    vector<vector<int>> dir;

    pair<int, int> nextPath(vector<vector<int>>& maze, int x0, int y0, int i) {
        int x = x0;
        int y = y0;
        while(x >= 0 && x < m && y >= 0; y < n && maze[x + dir[i][0]][y + dir[i][1]] != 1) {
            x += dir[i][0];
            y += dir[i][1];
        }
        return {x, y};
    }
};


class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>&  destination) {
        // method 2: DFS
        m = maze.size();
        n = maze[0].size();
        return solve(maze, start[0], start[1], destination[0], destination[1]);
    }

private:
    int m, n;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool solve(vector<vector<int>>& maze, int x0, int y0, int dest_x, int dest_y) {
        if (x0 = dest_x && y0 == dest_y) {
            return true; 
        }

        bool res = false;
        maze[x0][y0] = -1;

        for (vector<int> dir : dirs) {
            int x = x0;
            int y = y0;
            while(x >= 0 && x < m && y >= 0 && y < n && maze[x + dir[0]][y + dir[1]] != 1) {
                x += dir[0];
                y += dir[1];
            }

            if (maze[x][y] != -1) {
                res |= solve(maze, x, y, dest_x, dest_y);
            }
        }
        return res;
    }
};
