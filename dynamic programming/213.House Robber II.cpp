class Solution {
public:
    // method: dynamic programming
    // 1. two sub problem [0, nums.size() - 2], [1, nums.size() - 1]
    // 2. create vector "m" to store previous result
    // 3. m[i] = max(m[i - 2] + nums[i], m[i - 1])
    
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0];
        return max(rob1(nums, 0, n - 2), rob1(nums, 1, n - 1));
    }
private:
    int rob1(vector<int> nums, int begin, int end) {
        const int n = end - begin + 1;
        vector<int> m(n, 0);
        
        for (int i = begin; i <= end; ++i) {
            m[i - begin] = max( (i - begin >= 2  ? m[i - begin - 2] : 0) + nums[i], 
                                (i - begin >= 1 ? m[i - begin - 1] : 0) );
        }
        return m.back();
    }
    // time complexity: O(n)
    // space complexity: O(1)
};