class Solution {
public:
    int findMin(vector<int>& nums) {
        // method 1: Divide and conquer
        int l = 0;
        int r = nums.size() - 1;
        int m = (l + r) / 2;
        return min(solve(nums, l, m), solve(nums, m + 1, r));
    }
private:
    int solve(vector<int>& nums, int l, int r) {
        if (l >= r) return nums[r];
        if (nums[l] < nums[r]) return nums[l];
        else {
            int m = (l + r) / 2;
            return min(solve(nums, l, m), solve(nums, m + 1, r));
        }
    }
    // time complexity: O(nlogn)
    // space complexity: O(nlogn)
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        // method 2: binary search
        // --------------------------------------------------------------
        // !!! random choose one element and divide left and right at least 
        // one side have already been sorted => binary search
        // --------------------------------------------------------------
        // 1. choose pointer <l, r> (left & right)
        // 2. if (nums[l] < nums[r]) => subarray have been sorted => return nums[l]
        // 3. if (r == l) => subarray only have one element => return nums[l]
        // 4. mid = l + (r - l) / 2, divided two sub array [l, mid) [mid + 1, r)
        // 5. min(sub1, sub2) and do step 2-5
        
        // --------------------------------------------------------------
        const int n = nums.size();
        int l = 0; 
        int r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] < nums[r]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return nums[r];
    }
    // time complexity: O(nlogn)
    // space complexity: O(1)
};