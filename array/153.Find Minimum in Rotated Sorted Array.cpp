class Solution {
public:
    int findMin(vector<int>& nums) {
        // 1. brute force (not allow !)
        const int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, nums[i]);
        }
        return ans;
        // time complexity: O(n)
        // space complexity: O(1)
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        // 2. brute force (not allow !)
        sort(nums.begin(), nums.end());
        return nums[0];
        // time complexity: O(nlogn)
        // space complexity: O(1)
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        // 2. binary search
        // --------------------------------------------------------------
        // !!! random choose one element and divide left and right at least 
        // one side have already been sorted => binary search
        
        // --------------------------------------------------------------
        // binary search template
        // [left, right)
        
        // while (left < right) {
        //      mid = left + (right - left) // 2
        //      if f(mid) return mid;
        //      if g(mid)
        //          right = mid;        (left, mid]
        //      else
        //          left = mid + 1;     (mid + 1, right]
        // }
        
        // --------------------------------------------------------------
        // 1. choose pointer <l, r> (left & right)
        // 2. if (nums[l] < nums[r]) => subarray have been sorted => return nums[l]
        // 3. if (r == l) => subarray only have one element => return nums[l]
        // 4. mid = l + (r - l) / 2, divided two sub array [l, mid) [mid + 1, r)
        // 5. min(sub1, sub2) and do step 2-5
        
        // --------------------------------------------------------------
        return findMin(nums, 0, nums.size() - 1);
    }
    
private:
    int findMin(vector<int>& nums, int l, int r) {
        if (nums[l] < nums[r])  // subarray have been sorted
            return nums[l];
        if (l == r)             // subarray only have one element
            return nums[l];
        
        int m = l + (r - l) / 2;
        return min(findMin(nums, l, m), findMin(nums, m + 1, r));
    }
    // time complexity: O(nlogn)
    // space complexity: O(nlogn)
};