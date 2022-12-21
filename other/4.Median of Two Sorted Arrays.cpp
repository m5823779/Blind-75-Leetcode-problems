class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // brute force
        const int n = nums1.size();
        const int m = nums2.size();
        vector<int> nums;
        int i = 0;
        int j = 0;
        
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        if (i < n) nums.insert(nums.end(), nums1.begin() + i, nums1.end());
        if (j < m) nums.insert(nums.end(), nums2.begin() + j, nums2.end());
    
        int s = nums.size();
        if (s % 2 != 0) return nums[s / 2];
        else return (nums[s / 2] + nums[s / 2 - 1]) / 2.0; 
    }
    // time complexity: O(n + m)
    // space complexity: O(n + m)
};