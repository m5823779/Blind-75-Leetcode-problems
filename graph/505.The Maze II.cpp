class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // method 1: BFS
        const int m = maze.size();
        const int n = maze[0].size();
        
        int dir[5] = {0, 1, 0, -1, 0};

        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[start[0]][start[1]] = 0;
        
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int _x = x;
                int _y = y;
                int step = distance[x][y];
                while (_x >= 0 && _y >= 0 && _x < m && _y < n && maze[_x][_y] == 0) {
                    step += 1;
                    _x += dir[d];
                    _y += dir[d + 1];
                }
                _x -= dir[d];
                _y -= dir[d + 1];
                step -= 1;
                
                if (step < distance[_x][_y]) {
                    distance[_x][_y] = step;
                    q.push({_x, _y});
                }
            }
            
        }
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
};


class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // method 2: dijkstra's algorithm (using priority queue)
        // get maze rows and cols
        const int m = maze.size();
        const int n = maze[0].size();

        // initialize min distance from starting point to each cell
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[start[0]][start[1]] = 0;

        // min heap to store <distance from starting point, visiting cell>
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, start[0], start[1]});

        // define for direction 
        int dir[5] = {0, 1, 0, -1, 0};

        while (!pq.empty()) {
            auto [step, x, y] = pq.top();
            pq.pop();

            // rolling up, down, left and right
            for (int d = 0; d < 4; d++) {
                // new position
                int _x = x;
                int _y = y;
                int _step = step;
                // go stright until out, or hit the wall
                while (_x >= 0 && _y >= 0 && _x < m && _y < n && maze[_x][_y] == 0) {
                    _x += dir[d];
                    _y += dir[d + 1];
                    _step ++;
                }
                // cause already out, or hot the wall, so go back
                _x -= dir[d];
                _y -= dir[d + 1];
                _step--;

                // update min distance to new coordinate
                if (_step < dis[_x][_y]) {
                    dis[_x][_y] = _step;
                    pq.push({_step, _x, _y});
                }
            }
        }
        // if min distance to target still infinite means cant reach. return -1
        return dis[destination[0]][destination[1]] == INT_MAX ? -1 : dis[destination[0]][destination[1]];

    }
};