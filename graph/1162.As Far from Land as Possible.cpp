class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // method: BFS
        const int m = grid.size();
        const int n = grid[0].size();   
        
        int max_dis = -1;
        
        int dir[5] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        if (q.size() == 0 || q.size() == m * n) return -1;

        while (!q.empty()) {
            int s = q.size();
            max_dis += 1;

            for (int k = 0; k < s; k++) {
                auto p = q.front();
                q.pop();    

                for (int d = 0; d < 4; d++) {
                    int _i = p.first + dir[d];
                    int _j = p.second + dir[d + 1];

                    if (_i < 0 || _j < 0 || _i >= m || _j >= n) continue;
                    if (grid[_i][_j] == 0) {
                        grid[_i][_j] = 1;
                        q.push({_i, _j});
                    }
                }
            }    
        }
        return max_dis;
    }
    // time complexity: O(n^2)
    // space complexity: O(n^2)
};