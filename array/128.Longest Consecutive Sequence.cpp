class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // method 1: hash set
        // 1. create hast set, and place all elements into it (it will remove duplicate element)
        // 2. enumerate all elements n
        // 3. if n - 1 not exsit means it is the start of sequence
        // 4. check n + 1 exsit or not, if exsit length + 1
        // 5. repeat step 4 until n + 1 is not exsit
        
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        for (auto n : nums) {
            if (s.find(n - 1) == s.end()) {
                int length = 1;
                
                while (s.find(++n) != s.end()) { length += 1; }
                ans = max(ans, length);
            }
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // method 2: sorting
        // 1. sort the arry
        // 2. enumerate all elements
        // 3. check current = preverious + 1, if yes length + 1, if not reset length
        if (!nums.size()) return 0;
        
        int ans = 0;
        int length = 1;
        
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) continue;
            else if (nums[i] == nums[i - 1] + 1) length++;
            else {
                ans = max(ans, length);
                length = 1;
            }
        }
        return max(ans, length);
    }
    // time complexity: O(nlogn)
    // space complexity: O(1)
};