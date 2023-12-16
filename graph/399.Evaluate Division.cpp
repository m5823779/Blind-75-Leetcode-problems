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


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // method: DFS
        const int n = equations.size();
        for (int i = 0; i < n; i++) {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            set<string> visited;
            ans.push_back(dfs(visited, queries[i][0], queries[i][1]));
        }
        return ans;
    }
    map<string, vector<pair<string, double>>> mp;
    double dfs(set<string>& visited, string cur, const string dst) {
        if (mp.find(cur) == mp.end()) return -1;
        if (cur == dst) return 1.0;
        if (visited.find(cur) != visited.end()) return -1;
        visited.insert(cur);
        for (auto n : mp[cur]) {
            double res = dfs(visited, n.first, dst);
            if (res != -1) return res * n.second;
        }
        return -1;
    }
};