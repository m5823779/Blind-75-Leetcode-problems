class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // method: prefix sum + hash table
        map<int, int> mp;  // mod, frequency
        mp[0] = 1;

        int ans = 0;
        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            int mod = (prefix_sum % k + k) % k;

            if (mp.find(mod) != mp.end()) {
                ans += mp[mod];
            }
            mp[mod] += 1;
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(10)
};