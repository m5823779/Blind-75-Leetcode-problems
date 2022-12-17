class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // method 1: brute force (pick or not pick approach)
        return solve(nums, 0, INT_MIN);
    }
private:
    int solve(vector<int>& nums, int current, int previous) {
        if (current > nums.size() - 1) return 0;
        int pick = 0;
        int nopick = solve(nums, current + 1, previous);
        if (nums[current] > previous) 
            pick += solve(nums, current + 1, nums[current]) + 1;
        return max(pick, nopick);
    }
    // time complexity: O(2^n)
    // space complexity: O(n)
};


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


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // method 3: dynamic programming + binary search + greedy
        // example: [10, 9, 2, 5, 3, 5, 101, 18]
        //  number  |  dp
        //             []
        //    10       [10]
        //    9        [9]
        //    2        [2]
        //    5        [2, 5]
        //    3        [2, 3, 5]
        //    101      [2, 3, 5, 101]
        //    18       [2, 3, 5, 18]
        //
        // 1. create empty vector to store longest increasing subsequence
        // 2. enumerate element
        //      - append to the last, if it larger than the end of the vector
        //      - replace the element which is the smallest greater then it

        const int len = nums.size();
        vector<int> dp;

        for (int n : nums) {
            vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), n);
            if (it == dp.end()) dp.push_back(n);
            else {
                *it = n;
            }
        }
        return dp.size();
        // time complexity: O(nlogn)
        // space complexity: O(n)
    }
};