class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // method: two pointers
        int dis = INT_MAX;
        int closet;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return target;
                else if (sum > target) r--;
                else l++;

                if ( dis > abs(target - sum)) {
                    dis = abs(target - sum);
                    closet = sum;
                }
            }
        }
        return closet;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};