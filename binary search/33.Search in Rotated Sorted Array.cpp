class Solution {
public:
    int search(vector<int>& nums, int target) {
        // method: binary search
        // 1. declear three pointer 
        //      - left: 0
        //      - right: array's length - 1
        //      - mid: left + (right - left) / 2
        // 2. find sorted sub-array
        //      - if (nums[mid] > nums[left]) -> left partial is sorted
        //      - if (nums[mid] < nums[right]) -> right partial is sorted
        // 3. check target in sorted sub-array or not
        //      - if left partial is sorted: 
        //          if (nums[mid] > target and nums[left] < target) -> right = mid - 1
        //      - if right partia is sorted:
        //          if (nums[mid] < target and nums[right] > target) -> left = mid + 1
        const int len = nums.size();
        return binarySearch(nums, target, 0, len - 1);
    }
private:
    int binarySearch(vector<int>& nums, const int target, int l, int r) {
        if (l >= r && nums[l] != target) return -1;
        int m = l + (r - l) / 2;
        if (nums[m] == target) return m;
        
        // left sub-array sorted
        if (nums[m] >= nums[l]) {
            if (nums[m] < target || nums[l] > target) l = m + 1;
            else r = m - 1;
        }
        // right sub-array sorted
        else {
            if (nums[m] > target || nums[r] < target) r = m - 1;
            else l = m + 1;
        }
        
        return binarySearch(nums, target, l, r);
    }
    // time complexity: O(logn)
    // space complexity: O(logn)
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        // method: binary search
        // 1. declear three pointer 
        //      - left: 0
        //      - right: array's length - 1
        //      - mid: left + (right - left) / 2
        // 2. find sorted sub-array
        //      - if (nums[mid] > nums[left]) -> left partial is sorted
        //      - if (nums[mid] < nums[right]) -> right partial is sorted
        // 3. check target in sorted sub-array or not
        //      - if left partial is sorted: 
        //          if (nums[mid] > target and nums[left] < target) -> right = mid - 1
        //      - if right partia is sorted:
        //          if (nums[mid] < target and nums[right] > target) -> left = mid + 1
        int l = 0; 
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            }
            
            // left part sorted
            if (nums[m] > nums[r]) {
                if (nums[l] <= target && nums[m] >= target) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            // right part sorted
            else {
                if (nums[r] >= target && nums[m] <= target) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
    // time complexity: O(logn)
    // space complexity: O(1)
};