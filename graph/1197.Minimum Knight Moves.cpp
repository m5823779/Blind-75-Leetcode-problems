class Solution {
public:
    int minKnightMoves(int x, int y) {
        // method 1: BFS
        vector<vector<int>> dirs = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        visited.insert({0, 0});
        q.push({0, 0});
        int step = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int t = 0; t < s; t++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if (i == x && j == y) return step;

                for (auto dir : dirs) {
                    int _i = i + dir[0];
                    int _j = j + dir[1];
                    if (visited.find({_i, _j}) != visited.end()) continue;
                    visited.insert({_i, _j});
                    q.push({_i, _j});
                }
            }
            step++;
        }
        return -1;
    }
};



class Solution {
public:
    int minKnightMoves(int x, int y) {
        // method 1: BFS (optimize)
        
        // optimize
        x = abs(x);
        y = abs(y);
        
        vector<vector<int>> dirs = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        visited.insert({0, 0});
        q.push({0, 0});
        int step = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int t = 0; t < s; t++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if (i == x && j == y) return step;

                for (auto dir : dirs) {
                    int _i = i + dir[0];
                    int _j = j + dir[1];    
                    if (visited.find({_i, _j}) == visited.end() && _i >= -2 && _i <= x + 2 && _j >= -2 && _j <= y + 2) {
                        q.push({_i, _j});
                        visited.insert({_i, _j});
                    }
                }
            }
            step++;
        }
        return -1;
    }
    // time complexity: O(mn)
    // space complexity: O(mn)
};