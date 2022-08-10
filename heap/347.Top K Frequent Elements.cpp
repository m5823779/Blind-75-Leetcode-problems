class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // method 1: hash table + sorting
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


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // method 2: priority queue + max heap
        // 1. create unorded map to count appearance times of each element
        // 2. create priority queue, push unorded map into it
        // 3. pop out minimum element if queue size > k
        // 4. choose top K frequent element
        unordered_map<int, int> count;
        for(auto &num : nums) count[num]++;
        
        priority_queue<std::pair<int, int>> max_heap;
        for (auto &i : count) max_heap.push({i.second, i.first});

        vector<int> ans;
        while(k--) {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return ans;
    }
    // time complexity: O(nlogn)
    // space complexity: O(n)
};