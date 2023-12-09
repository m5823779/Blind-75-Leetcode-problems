class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // method: DFS
        const int n = equations.size();
        for (int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1 / values[i]});
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            unordered_set<string> visited;
            visited.insert(queries[i][0]);
            ans.push_back(dfs(visited, queries[i][0], queries[i][1]));
        }
        return ans;
    }
private:
    unordered_map<string, vector<pair<string, double>> > graph;
    double dfs(unordered_set<string>& visited, string src, string dst) {
        if (graph.find(src) == graph.end()) return -1;
        if (src == dst) return 1;

        for (pair<string, double> p : graph[src]) {
            if (visited.count(p.first)) continue;
            visited.insert(p.first);
            double res = dfs(visited, p.first, dst);
            if (res != -1) {
                return p.second * res;
            }                
        }
        return -1;
    }
};



class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> mp;
        const int n = equations.size();
        for (int i = 0; i < n; i++) {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        } 

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(bfs(mp, queries[i][0], queries[i][1]));
        }
        return ans;
    }

    double bfs(map<string, vector<pair<string, double>>>& mp, string cur, const string dst) {
        queue<pair<string, double>> q;
        set<string> visited;

        if (mp.find(cur) != mp.end()) {
            q.push({cur, 1.0});
            visited.insert(cur);
        }

        while (!q.empty()) {
            string tmp = q.front().first;
            double val = q.front().second;
            q.pop();

            if (tmp == dst) return val;
            for (auto p : mp[tmp]) {
                if (visited.find(p.first) != visited.end()) continue;
                visited.insert(p.first);
                q.push({p.first, val * p.second}); 
            }
        }
        return -1.0;
    }
};