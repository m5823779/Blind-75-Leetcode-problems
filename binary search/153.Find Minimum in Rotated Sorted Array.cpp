class Solution {
public:
    int findMin(vector<int>& nums) {
        // method 1: Divide and conquer
        return solve(nums, 0, nums.size() - 1);
    }
    int solve(vector<int>& nums, int l, int r) {
        // 找出 l-r 區間最小值
        // 終止條件: 若區間剩餘一個元素，該即為該區間最小
        if (l == r) return nums[l];
        // 檢查該區間是否排序 (左 < 右) -> 若已排序則最左及最小
        if (nums[l] < nums[r]) return nums[l];
        int m = l + (r - l) / 2;
        // 兩區間中返回最小的
        return min(solve(nums, l, m), solve(nums, m + 1, r));
    }
    // time complexity: O(nlogn)
    // space complexity: O(logn)
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        // method 2: binary search
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            // case 1: 
            // 沒有翻轉過，區間保持排序 -> 最小值位於左半邊
            // or 翻轉過，最小值位於左半邊
            if (nums[m] < nums[r]) r = m;
            // case 2:
            // 必定翻轉過，最小值(翻轉點)位於右半邊
            else l = m + 1;
        }
        return nums[r];
    }
    // time complexity: O(nlogn)
    // space complexity: O(1)
};