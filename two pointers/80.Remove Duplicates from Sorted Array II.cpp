class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // method: two pointers
        int counter = 1;
        int i = 1;
        for (int j = 1; j < nums.size(); j++) {
            // 當前元素和前一元素一樣
            if (nums[j] == nums[j - 1]) {
                counter++;
                // 不能連續出現超過兩次
                if (counter > 2) continue;
                else nums[i++] = nums[j];
            }
            // 當前元素和前一元素不一樣
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
        // method: two pointers
        if (nums.size() <= 2) return nums.size();
        int p = 2;
        for (int j = 2; j < nums.size(); j++) {
            // 當前元素和前兩個一致，因為排序過和前兩個一樣必定和前一個一樣，出現次數大於兩次
            if (nums[j] == nums[p - 2]) continue;
            nums[p++] = nums[j];
        }
        return p;
    }
};