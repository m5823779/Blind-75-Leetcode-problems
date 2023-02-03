class Solution {
public:
    // method 1: DFS (depth first search)
    // check are there any loop in graph

    // 1. create hash map (node -> neighbors)
    // 2. create container to store visited node (0: unkonw / 1: visting / 2: visited)
    // 3. enumerate all elements
    // 4. using DFS to check are there any loop

    // (0: unkonw / 1: visting / 2: visited)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<int>(numCourses, 0);
        
        for (vector<int> n : prerequisites)
            mp[n[0]].push_back(n[1]);
        
        for (int i = 0; i < numCourses; ++i)
            if (isCycle(i)) return false;
        
        return true;
    }
private:
    unordered_map<int, vector<int>> mp;  // node->neighbors
    vector<int> visited;
    
    bool isCycle(int class_id) {
        if (visited[class_id] == 2) return false;
        else if (visited[class_id] == 1) return true;
        else {
            visited[class_id] = 1;

            for (int n : mp[class_id])
                if (isCycle(n)) return true;
            
            visited[class_id] = 2;
            return false;
        }
    }
    // time complexity: O(V + E)
    // space complexity: O(n)
};


// method 2:
struct Graph {
    int numVertex;
    list<int> *adj;
    Graph(int n) {
        this->numVertex = n;
        adj = new list<int>[n];
    }
    void addEdge(int x, int y) {
        adj[x].push_back(y);
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        visited = vector<int>(numCourses, 0);
        graph = new Graph(numCourses);
        
        // create graph
        for (vector<int> p : prerequisites) {
            graph->adj[p[0]].push_back(p[1]);
        }

        // check any cycle appear 
        for (int i = 0; i < numCourses; i++) {
            if (haveCycle(i)) return false;
        }
        return true;
    }
private:
    Graph* graph;
    vector<int> visited;
    bool haveCycle(int class_id) {
        if (visited[class_id] == 1) return true;
        if (visited[class_id] == 2) return false;
        visited[class_id] = 1;

        for (int n : graph->adj[class_id]) {
            if (haveCycle(n)) return true;
        }
        visited[class_id] = 2;
        return false;
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // method 2: topological sort (BFS)
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        for (vector<int> p : prerequisites) {
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;
        vector<int> topological_sort;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            topological_sort.push_back(tmp);
            for (int n : graph[tmp]) {
                indegree[n]--;
                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        return numCourses == topological_sort.size();
    }
};