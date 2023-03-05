class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // method: two pointers
        int left = 1;
        const int n = nums.size();
        for (int right = 1; right < n; right++) {
            if (nums[right] == nums[right - 1]) {
                continue;
            }
            nums[left] = nums[right];
            left++;
        }
        return left;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};