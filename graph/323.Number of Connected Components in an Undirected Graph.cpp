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
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (vector<int> edge : edges) {
            union_vertices(edge[0], edge[1], parent);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                ans++;
            }
        }
        return ans;
    }
    
private:
    // find the x's parent
    int find_root(int x, vector<int>& parent) {
        int x_root = x;
        while (parent[x_root] != x_root) {
            x_root = parent[x_root];
        }
        return x_root;
    }
    void union_vertices(int x, int y, vector<int>& parent) {
        int x_root = find_root(x, parent);
        int y_root = find_root(y, parent);
        parent[y_root] = x_root;
    }
    // time complexity: O(nlogn)
    // space complexity: O(n)
};