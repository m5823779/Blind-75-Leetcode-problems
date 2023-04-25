class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // method: prefix sum + hash table
        const int n = nums.size();
        int prefix_sum = 0;
        unordered_map<int, int> mod_set;

        mod_set[0] = -1;
        for (int i = 0; i < n; i++) {
            prefix_sum += nums[i];
            int mod = prefix_sum % k;
            if (mod_set.find(mod) != mod_set.end()) {
                if (i - mod_set[mod] >= 2) {
                    return true;
                }
            }
            else {
                mod_set[mod] = i;
            }
        }
        return false;
    }
    // time complexity: O(n)
    // space complexity: O(10)
};