class NumArray {
private:
    vector<int> prefix_sum;
public:
    NumArray(vector<int>& nums) {
        // method: prefix sum
        const int n = nums.size();
        prefix_sum = vector<int>(n, 0);
        prefix_sum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix_sum[i] = nums[i] + prefix_sum[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right] - (left - 1 >= 0 ? prefix_sum[left - 1] : 0);
    }
    // time complexity: O(1)
    // space complexity: O(1)
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */