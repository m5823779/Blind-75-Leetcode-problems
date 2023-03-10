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


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // method 3: prefix sum + hash map
        // 1. create hash table to store <prefix sum, count>
        // 2.enumerate i, and calculate prefix sum (summary from 0 to i)
        // 3.check is (prefix sum - k) exist in hash table, if yes, add count to answer
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix_sum = 0;
        int num_combination = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            if (mp.find(prefix_sum - k) != mp.end()) {
                num_combination += mp[prefix_sum - k];
            }
            mp[prefix_sum]++;
        }
        return num_combination;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};