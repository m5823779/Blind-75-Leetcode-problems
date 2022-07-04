class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // index  0  1  2  3
        // nums  [1, 2, 4, 3]
        // start from index = 3 -> LIS[3] = 1
        // start from index = 2 -> LIS[2] = max(1, 1 + LIS[3]) -> max(1) [because nums[3] > nums[4]] = 1
        // start from index = 1 -> LIS[1] = max(1, 1 + LIS[2], 1 + LIS[3]) = 2
        // start from index = 0 -> LIS[0] = max(1, 1 + LIS[1], 1 + LIS[2], 1 + LIS[3]) = 3
        
        // method: dynamic programing (Depth First Search, DFS)
        // 1. create vector "LIS" to store result
        // 2. enumerate i [nums.size() - 1, 0]
        // 3. enumerate j [i + 1, nums.size()]
        // 4. if (nums[j] > nums[i]) max(LIS[i], 1 + LIS[j])
        // 5. return max(LIS)
        
        const int n = nums.size();
        
        vector<int> LIS(n, 1);
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
        return *max_element(LIS.begin(), LIS.end());
        // time complexity: O(n + (n - 1) + ... + 1) = O(n^2)
        // space complexity: O(n)
    }
};