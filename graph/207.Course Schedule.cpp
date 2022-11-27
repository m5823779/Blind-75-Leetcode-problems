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