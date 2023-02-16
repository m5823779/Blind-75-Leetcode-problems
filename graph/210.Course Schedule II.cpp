class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // method 1: topological sort (BFS)
        vector<int> ans;
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        for (vector<int> p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for (int adj : graph[tmp]) {
                indegree[adj]--;
                if (indegree[adj] == 0) {
                    q.push(adj);
                }
            }
        }

        if (ans.size() != numCourses) {
            ans.clear();
        }
        return ans;
    }
    // time complexity: O(V + E)
    // space complexity: O(V + E)
};