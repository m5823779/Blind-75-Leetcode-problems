class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // method 1: brute force
        const int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(nums[j]);
                if (s.size() == k) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space compleixty: O(n)
};


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // method 2: sliding window
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

private:
    int atMostKDistinct(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> mp;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]] += 1;
            while (mp.size() > k) {
                mp[nums[l]] -= 1;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }
    // time compleixty: O(n)
    // space complexity: O(n)
};