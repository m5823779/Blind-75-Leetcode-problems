class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // method: sliding window
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
private:
    int atMostK(vector<int>& nums, int k) {
        int res = 0;
        map<int, int> mp;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r] % 2] += 1;
            while (mp[1] > k) {
                mp[nums[l] % 2] -= 1;
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }
    // time compleixty: O(n)
    // space compleixty: O(n)
};