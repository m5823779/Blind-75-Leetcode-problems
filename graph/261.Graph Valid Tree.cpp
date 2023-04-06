class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // method: DFS
        visited = vector<bool>(n, false);
        vector<int> adj[n];
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if (haveCycle(adj, 0, -1)) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
private:
    vector<bool> visited;
    bool haveCycle(vector<int> *adj, int cur, int pre) {
        if (visited[cur]) {
            return true;
        }
        visited[cur] = true;

        for (int n : adj[cur]) {
            if (n == pre) {
                continue;
            }

            if (haveCycle(adj, n, cur)) {
                return true;
            }
        }
        return false;
    }
    // time complexity: O(V + E)
    // space complexity: O(V + E)
 };


 class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // method 2: Union find
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (vector<int>& edge : edges) {
            int x_root = find_root(edge[0]);
            int y_root = find_root(edge[1]);
            if (x_root == y_root) {
                return false;
            }
            parent[y_root] = x_root;
        }

        return n - 1 == edges.size();
    }
private:
    vector<int> parent;
    int find_root(int x) {
        int x_root = x;
        while (parent[x_root] != x_root) {
            x_root = parent[x_root];
        }
        return x_root;
    }
};