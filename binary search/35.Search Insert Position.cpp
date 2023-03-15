class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // method 1: brute force
        int insert_index = 0;
        while (insert_index < nums.size() && nums[insert_index] < target) {
            insert_index++;
        }
        return insert_index;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // method 2: binary search
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
    // time complexity: O(logn)
    // space complexity: O(1)
};