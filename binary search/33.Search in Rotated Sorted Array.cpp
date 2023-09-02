class Solution {
public:
    int search(vector<int>& nums, int target) {
        // method: Binary search
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target == nums[m]) return m;
            // m 以右為排序
            if (nums[m] < nums[r]) {
                // 檢查目標是否在已排序區間
                if (target <= nums[r] && target > nums[m]) l = m + 1;
                else r = m - 1;
            }
            // m 以左為排序
            else {
                // 檢查目標是否在已排序區間
                if (target >= nums[l] && target < nums[m]) r = m - 1;
                else l = m + 1;
            }
        }
        return -1;
    }
    // time complexity: O(logn)
    // space complexity: O(1)
};