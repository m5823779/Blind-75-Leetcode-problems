class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // method 1: brute force
        int num_combination = 0; 

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) {
                    num_combination += 1;
                }
            }
        }
        return num_combination;
    }
    // time complexity: O(n^2)
    // space complexity: O(n)
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // method 2: prefix sum
        const int n = nums.size();
        vector<int> prefix_sum(n + 1, 0);
        int num_combination = 0; 

        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
            for (int j = i; j >= 0; j--) {
                if (prefix_sum[i + 1] - prefix_sum[j] == k) {
                    num_combination += 1;
                }
            }
        }
        return num_combination;
    }
    // time complexity: O(n^2)
    // space complexity: O(n)
};