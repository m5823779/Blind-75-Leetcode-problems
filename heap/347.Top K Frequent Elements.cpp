class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // method 1: hash table
        // 1. create unordered map to count appearance times of each element
        // 2. sorting by appearance times
        // 3. choose top K frequent element
        vector<int> ans;
        
        const int n = nums.size();
        unordered_map<int, int> m;
        
        for (auto &n : nums) m[n]++;
        
        vector<std::pair<int, int>> tmp;
        // vector<std::pair<int, int>> tmp(m.begin(), m.end());
        
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it) tmp.push_back(*it);
        // for (const auto &i : tmp) tmp.push_back(i);
        
        std::sort(tmp.begin(), tmp.end(), [] (const auto &a, const auto &b) {return a.second > b.second;});
        // std::sort(tmp.begin(), tmp.end(), [] (std::pair<int, int> &a, std::pair<int, int> &b) {return a.second > b.second;});
        
        for(int i = 0; i < k; ++i) ans.push_back(tmp[i].first);
        
        return ans;
    }
    // time complexity: O(nlogn)
    // space complexity: O(n)
};