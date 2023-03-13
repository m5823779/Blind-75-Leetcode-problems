class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // method : binary search
        int l = 0;
        int r = nums.size() - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (nums[m] > nums[m + 1]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return (nums[l] > nums[r]) ? l : r;
        // time complexity: O(logn)
        // space complexity: O(1)
    }
};