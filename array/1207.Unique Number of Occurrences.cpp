class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // method: Hash table
        unordered_map<int, int> mp;  // number, count
        for (int& n : arr) {
            mp[n]++;
        }  

        vector<int> bucket(arr.size() + 1, 0);
        for (auto& p : mp) {
            if (bucket[p.second]) return false;
            else {
                bucket[p.second]++;
            }
        }
        return true;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // method: Hash table
        unordered_map<int, int> mp;  // number, count
        for (int& n : arr) {
            mp[n]++;
        }  

        unordered_set<int> occur;
        for (auto& p : mp) {
            occur.insert(p.second);
        }
        return occur.size() == mp.size();
    }
    // time complexity: O(n)
    // space complexity: O(n)
};