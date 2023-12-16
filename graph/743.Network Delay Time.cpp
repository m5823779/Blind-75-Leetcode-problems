class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // method: Dijkstar's, algorithm
        vector<bool> visited(n, false);
        vector<int> shortest_dis(n, INT_MAX);
        shortest_dis[k - 1] = 0;

        for (int i = 0; i < n; i++) {
            int visiting = findMin(visited, shortest_dis) + 1;
            if (visiting == 0) return -1;

            visited[visiting - 1] = true;
            for (vector<int> t : times) {
                if (t[0] == visiting) {
                    shortest_dis[t[1] - 1] = min(shortest_dis[t[1] - 1], shortest_dis[visiting - 1] + t[2]);
                }
            }
        }

        int ans = *max_element(shortest_dis.begin(), shortest_dis.end());
        if (ans == INT_MAX) {
            return -1;
        }
        else {
            return ans;
        }
    }
private:
    int findMin(vector<bool>& visited, vector<int>& shortest_path) {
        int small_id = -1;
        int small_val = INT_MAX;
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                if (shortest_path[i] < small_val) {
                    small_val = shortest_path[i];
                    small_id = i;
                }
            }
        }
        return small_id;
    }
    // time complexity: O(n^2)
};


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for(vector<int> time : times) mp[time[0]].push_back({time[1], time[2]});

        vector<int> dis(n + 1, INT_MAX); // <node, distance>
        dis[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // <distance node>
        pq.push({0, k});
        while (!pq.empty()) {
            pair<int, int> tmp = pq.top();
            pq.pop();
            int d = tmp.first;
            int c = tmp.second;
            for (auto neighbor : mp[c]) {
                int next = d + neighbor.second;
                if (next < dis[neighbor.first]) {
                    dis[neighbor.first] = next;
                    pq.push({next, neighbor.first});
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;
            else {
                ans = max(ans, dis[i]);
            }
        }
        return ans;
    }
};