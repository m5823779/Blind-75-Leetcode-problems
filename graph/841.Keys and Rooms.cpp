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


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // method 2: BFS
        const int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int r : rooms[v]) {
                if (visited[r]) continue;
                visited[r] = true;
                q.push(r);
            }
        }
        return find(visited.begin(), visited.end(), false) == visited.end();
    }
};