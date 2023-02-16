class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // method 1: binary search + linear search (brute force)
        vector<int> ans;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                l = m;
                r = m;                
                while (l - 1 >= 0 && nums[l - 1] == target) {
                    l--;
                }
                while (r + 1 < nums.size() && nums[r + 1] == target) {
                    r++;
                }
                return {l , r};
            }
            else if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return {-1, -1};
    }
    // time complexity: O(n)
    // space complexity: O(1)
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // method 2: binary search  
        if (nums.size() == 0) return {-1, -1};
        return {findMostLeft(nums, target), findMostRight(nums, target)};      
    }

private:
    // binary seach function
    int findMostLeft(vector<int>& nums, int target) {
        int most_left = -1;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                most_left = m;
                r = m - 1;
            }
            else if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return most_left;
    }

    int findMostRight(vector<int>& nums, int target) {
        int most_right = -1;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                most_right = m;
                l = m + 1;
            }
            else if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return most_right;
    }
    // time complexity: O(logn)
    // space complexity: O(1)
};