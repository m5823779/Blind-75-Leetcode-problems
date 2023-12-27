class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        int ans = 0;
        vector<int> rank(n, 0);
        for (auto road : roads) {
            rank[road[0]]++;
            rank[road[1]]++;
            connect[road[0]][road[1]] = true;
            connect[road[1]][road[0]] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (connect[i][j]) {
                    ans = max(ans, rank[i] + rank[j] - 1);
                }
                else ans = max(ans, rank[i] + rank[j]);
            }
        }
        return ans;
    }
};