class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // method 1: sort
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int j = (nums.size() - 1) / 2;
        int k = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) { nums[i] = tmp[j--]; }
            else { nums[i] = tmp[k--]; }
        }
        // time complexity: O(nlogn)
        // space complexity: O(1)
    }
};