class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // method 1: brtue force
        // first loop: rotate k times
        for (int i = 0; i < k; i++) {
            
            // second loop: move 1 step for all the element
            int previous = nums[nums.size() - 1];
            for (int j = 0; j < nums.size(); j++) {
                int current = nums[j];
                nums[j] = previous;
                previous = current;
            }
        }
    }
    // time complexity: O(k * n)
    // space complexity: O(1)
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // method 2: extra memory
        const int n = nums.size();
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            int id = (i + k) % n;
            tmp[id] = nums[i];
        }
        nums = tmp;
    }
    // time complexity: O(n)
    // space compleixty: O(n)
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // method 2: reverse
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // method 3: reverse
        const int n = nums.size();
        k = k % n;
        revert(nums, 0, n - 1);
        revert(nums, 0, k - 1);
        revert(nums, k, n - 1);
    }
private:
    void revert(vector<int>& nums, int l, int r) {
        while (l < r) {
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
    }
};