class Solution {
public:
    int search(vector<int>& nums, int target) {
        // method: binary search
        const int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = (l + r);
            if (nums[m] > target) r = m - 1;
            else if (nums[m] < target) l = m + 1;
            else return m;
        }
        return -1;
    }
    // time complexity: O(logn)
    // space complexity: O(1)
};