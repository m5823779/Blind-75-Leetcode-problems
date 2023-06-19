class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // method 1: two pointers
        const int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == val) {
                continue;
            }
            else {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};