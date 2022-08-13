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


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // method 3: priority queue + min heap
        // 1. create unorded map to count appearance times of each element
        // 2. create priority queue, push unorded map into it
        // 3. pop out minimum element if queue size > k
        // 4. choose top K frequent element
        unordered_map<int, int> c;
        for (auto num : nums) c[num]++;
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;  // small -> big
        for (auto it = c.begin(); it != c.end(); ++it) {
            pq.push({ it->second, it->first });
            if (pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    // time complexity: O(nlogk)
    // space complexity: O(n)
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // method 4: bucket sorting
        // example:
        // [4, 4, 4, 5, 5, 6, 6]
        // map
        //  value:    4     5     6
        //  count:    3     2     2
        
        //  bucket
        //  count:    1     2     3
        //  value:   {}   {5, 6}  {4}
        
        // 1. create unordered map to count appearance  times of each element
        // 2. create vector (bucket) which length equal to array's size
        // 3. let vector's index to be an appearance  times, then insert element into it
        // 4. choose top k frequent element start from the end of the vector
        
        unordered_map<int, int> count;
        for (auto &num : nums) count[num]++;
        
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &i : count) bucket[i.second].push_back(i.first);
        
        vector<int> ans;
        for (int i = bucket.size() - 1;  i > 0; --i) {
            for (auto j : bucket[i]) {
                if (ans.size() < k) ans.push_back(j);
            }
        } 
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // method 5: bucket sorting (optimize)
        // example:
        // [4, 4, 4, 5, 5, 6, 6]
        //  map
        //  value:    4     5     6
        //  count:    3     2     2
        //  most appearance  times = 3
        
        //  bucket
        //  count:    3     2
        //  value:   {4}   {5, 6}
        
        // 1. create unordered map to count appearance times of each element [value, count]
        // 2. find maximum appearance  times
        // 3. create unordered map [count, value]
        // 4. enumerate from [maximum appearance  times, 1] insert value into ans vector 
        
        unordered_map<int, int> count;
        int max_aparence;
        for (auto &num : nums) max_aparence = max(max_aparence, ++count[num]);
        
        unordered_map<int, vector<int>> bucket;
        for (auto &i : count) bucket[i.second].push_back(i.first);
        
        vector<int> ans;
        for(int i = max_aparence; i > 0; --i) {
            unordered_map<int, vector<int>>::iterator it = bucket.find(i);
            if (it == bucket.end()) continue;
            ans.insert(ans.end(), it->second.begin(), it->second.end());
            if (ans.size() >= k) return ans;
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};