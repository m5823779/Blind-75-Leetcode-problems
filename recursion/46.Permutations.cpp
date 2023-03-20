class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // method: recursive (backtracking)
        vector<int> sub_ans;
        used = vector<bool>(nums.size(), false);
        solve(nums, sub_ans);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<bool> used;
    void solve(vector<int>& nums, vector<int> sub_ans) {
        if (sub_ans.size() == nums.size()) {
            ans.push_back(sub_ans);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;

            sub_ans.push_back(nums[i]);
            solve(nums, sub_ans);
            sub_ans.pop_back();

            used[i] = false;
        }
    }
    // time complxity: O(n!)
    // space complexity: O(n)
};
