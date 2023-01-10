class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // mehtod: recursion (pick / not-pick approach)
        vector<int> sub_ans;
        solve(nums, 0, sub_ans);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int cur, vector<int> sub_ans) {
        // base case
        if (cur >= nums.size()) {
            ans.push_back(sub_ans);
            return;
        }

        // not-pick
        solve(nums, cur + 1, sub_ans);

        // pick
        sub_ans.push_back(nums[cur]);
        solve(nums, cur + 1, sub_ans);
        sub_ans.pop_back();
    }
    // time complexity: O(2^n)
    // space complexity: O(n)
};