class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // method 1: sorting
        // 1. create map to store sorted string & original string
        // 2. enumerate strs[i], and sort each of them
    
        const int n = strs.size();
        
        map<string, vector<string>> m;
        
        for (int i = 0; i < n; ++i) {
            string tmp  = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for (auto i : m) ans.push_back(i.second);
        // for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) ans.push_back((*it).second);
        return ans;
    }
    // time complexity: O(m * nlogn)
    // space complexity: O(m)
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // method 2: hash map
        // 1. create map to store counter & original string
        // 2. enumerate strs[i]
        // 3. create vector to count apparance times of character for each string
    
        const int n = strs.size();
        
        map<vector<int>, vector<string>> m;
        
        for (int i = 0; i < n; ++i) {
            vector<int> c(26, 0);
            for (auto j : strs[i]) {
                c[j - 'a']++;
            }
            m[c].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for (auto i : m) ans.push_back(i.second);
        // for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) ans.push_back((*it).second);
        return ans;
    }
    // time complexity: O(m * n), which m is vector length, n is average string length
    // space complexity: O(m * 26)
};