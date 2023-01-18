class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // method: recursive (backtracking)
        vector<int> sub_ans;
        used = vector<bool>(nums.size(), false);
        solve(nums, sub_ans, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<bool> used;
    void solve(vector<int>& nums, vector<int> sub_ans, int cur) {
        if (cur >= nums.size()) {
            ans.push_back(sub_ans);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            sub_ans.push_back(nums[i]);
            solve(nums, sub_ans, cur + 1);
            sub_ans.pop_back();
            used[i] = false;
        }
    }
    // time complxity: O(n!)
    // space complexity: O(n)
};