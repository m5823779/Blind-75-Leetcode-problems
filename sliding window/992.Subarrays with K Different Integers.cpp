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
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k ) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int distinct = 0;
        map<int, int> mp; 
        for (r = 0; r < nums.size(); r++) {
            if (mp[nums[r]] == 0) {
                distinct += 1;
            }
            mp[nums[r]]++;

            while (distinct > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    distinct -= 1;
                }
                l++;
            }

            ans += (r - l + 1);
        }
        return ans;
    }
    // time compleixty: O(n)
    // space complexity: O(n)
};