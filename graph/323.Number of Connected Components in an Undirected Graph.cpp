class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // method 1: DFS 
        vector<int> graph[n];
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int num_comp = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            num_comp += 1;
            dfs(graph, visited, i);
        }
        return num_comp;
    }
private:
    void dfs(vector<int>* graph, vector<bool>& visited, int cur) {
        if (visited[cur]) return;

        visited[cur] = true;
        for (int n : graph[cur]) {
            dfs(graph, visited, n);
        }
    }
    // time complexity: O(V + E)
    // space complexity: O(V + E)
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // method 2: BFS 
        vector<int> graph[n];
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int num_comp = 0;
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            q.push(i);
        
            num_comp += 1;
            while (!q.empty()) {
                int tmp = q.front();
                q.pop();

                for (int n : graph[tmp]) {
                    if (visited[n] == false) {
                        visited[n] = true;
                        q.push(n);
                    }
                }
            }
        }
        return num_comp;
    }
    // time complexity: O(V + E)
    // space complexity: O(V + E)
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // method: Union find
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto edge : edges) {
            union_vertex(edge[0], edge[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == find_parent(i)) ans++;
        }
        return ans;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int find_parent(int x) {
        int p = x;
        while (parent[p] != p) {
            p = parent[p];
        }
        return p;
    }

    void union_vertex(int x, int y) {
        int px = find_parent(x);
        int py = find_parent(y);
        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[px] = py;
            rank[py]++;
        }
    }
    // time complexity: O(nlogn)
    // space complexity: O(n)
};