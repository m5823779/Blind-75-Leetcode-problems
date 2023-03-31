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
        vector<int> visited(n + 1, false);
        vector<int> dis(n + 1, INT_MAX);
        // pair< dis, node >
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[k] = 0;
        pq.push(make_pair(0, k));

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            int visiting = p.second;
            if (visited[visiting]) {
                continue;
            }
            visited[visiting] = true;

            for (vector<int> time : times) {
                if (time[0] == visiting) {
                    if (dis[visiting] + time[2] < dis[time[1]]) {
                        dis[time[1]] = dis[visiting] + time[2];
                        pq.push(make_pair(dis[time[1]], time[1]));
                    }
                }
            }
        }

        int res = 0;
        for(int i = 1; i <= n;i++)
        {
            if(dis[i] == INT_MAX)
                return -1;
            res = max(res, dis[i]);
        }
		return res;
    }
};