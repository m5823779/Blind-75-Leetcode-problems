class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int k = 4;
        vector<int> sub_ans;
        kSum(k, nums, sub_ans, 0, target);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void kSum(int k, vector<int>& nums, vector<int>& sub_ans, int id, long long target) {
        if (k != 2) {
            for (int i = id; i < nums.size(); i++) {
                if (i > id && nums[i] == nums[i - 1]) continue;
                sub_ans.push_back(nums[i]);
                kSum(k - 1, nums, sub_ans, i + 1, (long long)target - nums[i]);
                sub_ans.pop_back();
            }
        }
        else {
            int l = id;
            int r = nums.size() - 1;
            while (l < r) {
                long long sum = nums[l] + nums[r];
                if (sum > target) {
                    r--;
                }
                else if (sum < target) {
                    l++;
                }
                else {
                    sub_ans.push_back(nums[l]);
                    sub_ans.push_back(nums[r]);
                    ans.push_back(sub_ans);
                    sub_ans.pop_back();
                    sub_ans.pop_back();
                    
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                }
            }
        }
    }
};