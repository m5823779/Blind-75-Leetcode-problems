class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // method: DFS
        const int n = isConnected.size();
        visited = vector<bool>(n, false);
        int num_provinces = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            num_provinces += 1;
            dfs(isConnected, i);
        } 
        return num_provinces;
    }
private:
    vector<bool> visited;
    void dfs(vector<vector<int>>& isConnected, int i) {
        if (visited[i]) return;
        visited[i] = true;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1) {
                dfs(isConnected, j);
            }
        }
    }
    // time complexity: O(n^2)
    // space complexity: O(n)
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // method: BFS
        const int n = isConnected.size();
        vector<bool> visited(n, false);

        int num_provinces = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;

            num_provinces += 1;
            q.push(i);

            while (!q.empty()) {
                int visiting = q.front();
                q.pop();

                for (int j = 0; j < n; j++) {
                    if (isConnected[visiting][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        return num_provinces;
    }
    // time complexity: O(n^2)
    // space compelxity: O(n)
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // method 3: Union find
        const int n = isConnected.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    union_vertices(i, j, parent);
                }
            }
        }

        int num_provinces = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                num_provinces += 1;
            }
        }
        return num_provinces;
    }

private:
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
    // time complexity: O(n^2 * logn)
    // space complexity: O(n)
};