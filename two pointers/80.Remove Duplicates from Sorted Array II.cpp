class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // method 1: two pointers
        int counter = 1;
        int i = 1;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] == nums[j - 1]) {
                counter++;
                if (counter > 2) {
                    continue;
                }
                else {
                    nums[i++] = nums[j];
                }
            }
            else {
                counter = 1;
                nums[i++] = nums[j];
            }
        }
        return i;
    }
    // time compleixty: O(n)
    // space complexity: O(1)
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // method 2: two pointers
        int l = 0;
        int r = 0;
        int i = 0;
        while (r < nums.size()) {
            if (nums[r] == nums[l]) {
                if (r - l + 1 > 2) {
                    r++;
                }
                else {
                    nums[i++] = nums[r++];
                }
            }
            else {
                l = r;
                nums[i++] = nums[r++];
            }
        }
        return i;
    }
    // time compleixty: O(n)
    // space complexity: O(1)
};