class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // method 1: brute force 
        vector<int> ans;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            int target = nums[i];

            int j = i + 1;
            while (j < i + n) {
                if (nums[j % n] > target) {
                    ans.push_back(nums[j % n]);
                    break;
                }
                j++;
            }
            if (j >= i + n) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};