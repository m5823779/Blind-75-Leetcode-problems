// Not pass test case ["z", "z"]

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        const int n = words.size();
        for (int i = 1; i < n; i++) {
            int j = 0;
            int k = 0;

            while (j < words[i - 1].size() && k < words[i].size() && words[i - 1][j] == words[i][k]) {
                j++;
                k++;
            }

            adj[words[i - 1][j]].push_back(words[i][k]);
            adj[words[i][k]];
            indegree[words[i][k]] += 1;
            indegree[words[i - 1][j]];
        }

        string ans;
        queue<char> q;
        for (auto d : indegree) {
            if (d.second == 0) {
                q.push(d.first);
            }
        }

        while (!q.empty()) {
            char tmp = q.front();
            q.pop();
            ans += tmp;

            for (char neighbor : adj[tmp]) {
                indegree[neighbor] -= 1;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    string alienOrder(vector<string>& words) {
        // method: topological sort
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Init
        for(string& word : words){
            for(char c : word){
                indegree[c] = 0;
                adj[c] = vector<char>();
            }
        }

        // Building Graph
        for(int i = 1; i < words.size(); i++){
            string w1 = words[i - 1], w2 = words[i];
            if (w1.size() > w2.size() && w1.find(w2) == 0) {  // To handle a test case
                return "";
            }
            for(int j = 0; j < min(w1.size(), w2.size()); j++){
                char c1 = w1[j];
                char c2 = w2[j];
                if(c1 != c2) {      // For first Diff char
                    adj[c1].push_back(c2);
                    indegree[c2]++;
                    break;
                }
            }
        }

        string ans;
        queue<char> q;
        for (auto d : indegree) {
            if (d.second == 0) {
                q.push(d.first);
            }
        }

        while (!q.empty()) {
            char tmp = q.front();
            q.pop();
            ans += tmp;

            for (char neighbor : adj[tmp]) {
                indegree[neighbor] -= 1;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans.size() == adj.size() ? ans : "";
    }
};