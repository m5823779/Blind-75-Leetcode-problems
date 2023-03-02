class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // method 1: brute force 
        int duplicate = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    duplicate = nums[i];
                }
            }
        }
        return duplicate;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // method 2: hash table 
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return nums[i];
            }
            s.insert(nums[i]);
        }
        return -1;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // method 3: Sorting
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
    }
    // time complexity: O(nlogn)
    // space complexity: O(1)
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // method 3: Two pointers (Floyd)
        int slow = 0; 
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        int entry = 0;
        while (entry != slow) {
            entry = nums[entry];
            slow = nums[slow];
        }
        return entry;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};