class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // method 1: DFS
        graph = vector<vector<int>>(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, visited);
    }
private:
    vector<vector<int>> graph;
    bool dfs(int cur, int destination, vector<bool>& visited) {
        if (visited[cur]) return false;
        if (cur == destination) return true;
        visited[cur] = true;
        for (int neighbor : graph[cur]) {
            if (dfs(neighbor, destination, visited)) return true;
        }
        return false;
    }
};


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // method 2: BFS
        vector<vector<int>> graph(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        visited[source] = true;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int tmp = q.front();
                q.pop();
                if (tmp == destination) return true;
                for (int neighbor : graph[tmp]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};