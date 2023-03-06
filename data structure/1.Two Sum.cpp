class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // method 1: brute force 
        // 1. enumerate all pair (i, j)
		// 		0 <= i < j <= n - 1 
        // 2. check the sum is equal to the target or not
        const int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        
        return {0, 0};
        // time complexity: O(n^2)
        // space complexity: O(1)
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // method 2: hash table: Allow O(1) to get the target value
        // The answer return index not value, hash set is unorder, we use hash map
        
        // 1. create map (hash table)
        // 2. store <element, index>
        // 3. enumerate all element var, find (target - ver) is in the map or not
        const int n = nums.size();
        map<int, int> m;
        
        for (int i = 0; i < n; ++i) {
            m[nums[i]] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            int left = target - nums[i];
            if(m.find(left) != m.end() && i != m[left])
			// if(m.count(left) && i != m[left])
                return {i, m[left]};
        }
        return {0, 0};
        // time complexity: O(n)
        // space complexity: O(n)
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // method 2: hash table: Allow O(1) to get the target value
        // The answer return index not value, hash set is unorder, we use hash map
        
        // 1. create map (hash table)
        // 2. store <element, index>
        // 3. enumerate all element var, find (target - ver) is in the map or not
        map<int, int> m;  // key: num, value: index
        
        for (int i = 0; i < nums.size(); ++i) {
            int left = target - nums[i];
            if (m.find(left) != m.end() && m[left] != i) return {i, m[left]};
            else m[nums[i]] = i;
        }
        return {};
        // time complexity: O(n)
        // space complexity: O(n)
    }
};