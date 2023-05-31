// practice again

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // method 1: brute force 
        // 1. choose start(i) & end(j) point
        // 2. enumerate from <i to j> add toghter
        
        // i=0, j=0 => sum = nums[0]
        // i=0, j=1 => sum = nums[0] + nums[1]
        // i=0, j=2 => sum = nums[0] + nums[1] + nums[2]
        // i=0, j=3 => sum = nums[0] + nums[1] + nums[2] + nums[3]..
        
        const int n = nums.size();
        int ans = nums[0];
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += nums[k];
                }
                ans = max(ans, sum);
            }
        }
    return ans;
    // time complexity: O(n^3)
    // space complexity: O(1)
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // method 2: brute force (optimize version)
        // 1. choose start(i) & end(j) point
        // 2. enumerate from <i to j> add toghter
        
        // sum = 0
        // i=0, j=0 => sum = sum + nums[0]
        // i=0, j=1 => sum = sum + nums[1]
        // i=0, j=2 => sum = sum + nums[2]
        // i=0, j=3 => sum = sum + nums[3]...
        // i=0, j=k => sum = sum + nums[k]
        
        const int n = nums.size();
        int ans = nums[0];
        
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                ans = max(ans, sum);
            }
        }
    return ans;
    // time complexity: O(n^2)
    // space complexity: O(1)
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // method 3: dynamic programming
        // [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        // [-2, 1, -2, 4,  3, 5, 6,  1, 5]
        // 1. create vector "sum" to store summary
        // 2. enumerate nums[i]
        // 3. if (sum[i - 1] <= 0 & nums[i] > sum[i - 1]) => sum[i] = nums[i]
        //    else => sum[i] = sum[i - 1] + nums[i]
        
        const int n = nums.size();
        vector<int> sum(n);
        sum[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            // (sum[i - 1] <= 0 && nums[i] > sum[i - 1]) ? sum[i] = nums[i] : sum[i] = sum[i - 1] + nums[i];
            sum[i] = max(nums[i], sum[i - 1] + nums[i]);
        }
        auto ans = max_element(sum.begin(), sum.end());
        return *ans;
    // time complexity: O(n)
    // space complexity: O(n)
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // method 4: greedy (kadane's algorithm)
        int curSum = 0;
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            curSum = max(nums[i], nums[i] + curSum);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};