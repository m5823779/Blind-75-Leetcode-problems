class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // method: Union find
        const int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (vector<int>& edge : edges) {
            int x_root = find_root(edge[0], parent);
            int y_root = find_root(edge[1], parent);
            if (x_root == y_root) {
                return edge;
            }
            if (rank[x_root] > rank[y_root]) {
                parent[y_root] = x_root;
            }
            else if (rank[x_root] < rank[y_root]) {
                parent[x_root] = y_root;
            }
            else {
                parent[y_root] = x_root;
                rank[x_root]++;
            }
        }
        return {};
    }
private:
    int find_root(int x, vector<int>& parent) {
        int x_root = x;
        while (parent[x_root] != x_root) {
            x_root = parent[x_root];
        }
        return x_root;
    }
};