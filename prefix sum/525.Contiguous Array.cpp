class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // method 1: brute force 
        const int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int len = j - i + 1;
                if (len % 2 == 0 && sum == len / 2) {
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // method 1: brute force 
        const int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int zero = 0;
            int one = 0;
            for (int j = i; j < n; j++) {
                if (nums[j]) one += 1;
                else zero += 1;
                if (one == zero) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // mothod 2: prefix sum + hash table
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        int ans = 0;
        int prefix_sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            prefix_sum += nums[i];

            if (mp.find(prefix_sum) != mp.end()) {
                ans = max(ans, i - mp[prefix_sum]);
            }
            else {
                mp[prefix_sum] = i;
            }
        }
        return ans;
    }

    // time complexity: O(n)
    // spac complexity: O(n)
};