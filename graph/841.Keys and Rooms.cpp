class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // method: DFS
        n = rooms.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                adj[i].push_back(rooms[i][j]); 
            }
        }

        vector<int> visited(n, false);
        dfs(adj, visited, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }

private:
    int n;
    void dfs(vector<int>* adj, vector<int>& visited, int room) {
        if (visited[room]) return;
        visited[room] = true;
        for (int n : adj[room]) {
            dfs(adj, visited, n);
        }
    }
    // time complexity: O(n)
    // space complexity: O(n)
};