class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // method 1: sort
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int j = (nums.size() - 1) / 2;
        int k = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) { nums[i] = tmp[j--]; }
            else { nums[i] = tmp[k--]; }
        }
        // time complexity: O(nlogn)
        // space complexity: O(1)
    }
};


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // method 2: quick select
        int medium = quickSelect(nums, (nums.size() + 1) / 2, 0, nums.size() - 1);
        #define A(i) nums[(1 + 2 * i) % (n | 1)]

        int n = nums.size(), i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > medium) swap(A(i++), A(j++));
            else if (A(j) < medium) swap(A(j), A(k--));
            else ++j;
        }
    }
private:
    int quickSelect(vector<int>& nums, int k, int l, int r) {
        int pivot = nums[r];
        int j = l - 1;
        for (int i = l; i < r; i++) {
            if (nums[i] > pivot) {
                j++;
                swap(nums[i], nums[j]);
            }
        }
        j++;
        swap(nums[r], nums[j]);
        if (j == k - 1) return nums[j];
        else if (j > k - 1) return quickSelect(nums, k, l, j - 1);
        else return quickSelect(nums, k, j + 1, r);
    }
    // time complexity: O(n)
    // space complexity: O(1)
};