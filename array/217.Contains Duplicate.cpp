class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // method 1. brute forece
        // 1. enumerate pair <i, j>
        // 2. if nums[i] = nums[j], return true
        const int n = nums.size();
        for(int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // method 2. hash table
        // 1. create map (hash table)
        // 2. enumerate nums[i] store in hash table
        const int n = nums.size();
        map<int, int> m;
        
        for (int i = 0; i < n; ++i) {
            if (m.find(nums[i]) != m.end()) return true;
            m[nums[i]] = i;
        }
        return false;
        // time complexity: O(n)
        // space complexity: O(n)
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // method 3. sorting (while)
        // 1. sorting 
        // 2. define <i, j> pointer, which j = i + 1
        // 3. return "true" if nums[i] == nums[j] else return "false"
        // 4. move pointer <i, j> one step
        const int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = i + 1;
        
        while (j < n) {
            if (nums[i] == nums[j]) return true;
            ++i;
            ++j;
        }
        return false;
        // time complexity: O(n)
        // space complexity: O(1)
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // method 3_1. sorting (for loop)
        // 1. sorting 
        // 2. enumerate nums[i], which i < length - 1
        // 3. define j = i + 1
        // 4. return "true" if nums[i] == nums[j] else return "false"
        const int n = nums.size();
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; ++i) {
            int j = i + 1;
            if (nums[i] == nums[j]) return true;
        }
        return false;
        // time complexity: O(n)
        // space complexity: O(1)
    }
};