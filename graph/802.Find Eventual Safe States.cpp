class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // method: DFS
        const int n = graph.size();
        // 0: know / 1: visiting / 2: have cyclic (unsave) / 3: no cycle (save) 
        vector<int> status(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dfs(graph, status, i) == 3) {
                ans.push_back(i);
            }
        }
        return ans;
    }
private:
    int dfs(vector<vector<int>>& graph, vector<int>& status, int cur) {
        if (status[cur] == 1) {
            return 2;
        }
        if (status[cur] == 2) {
            return 2;
        }
        if (status[cur] == 3) {
            return 3;
        }

        status[cur] = 1;
        for (int n : graph[cur]) {
            if (dfs(graph, status, n) == 2) {
                return status[n] = 2;
            }
        }
        return status[cur] = 3;
    }
    // time complexity: O(V + E)
    // space complexity: O(V + E)
};


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // method 2: topological sort
        const int n = graph.size();
        unordered_map<int, vector<int>> mp;
        vector<int> outdegree(n, 0);

        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
            for (int j = 0; j < graph[i].size(); j++) {
                mp[graph[i][j]].push_back(i);
            }
        }

        set<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            ans.insert(tmp);
            
            for (int k : mp[tmp]) {
                outdegree[k]--;
                if (outdegree[k] == 0) q.push(k);
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};