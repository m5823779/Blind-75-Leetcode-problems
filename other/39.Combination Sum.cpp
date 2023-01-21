class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // method : recursion
        vector<int> sub_ans;
        solve(candidates, target, sub_ans, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, vector<int> sub_ans, int cur) {
        // base case
        if (cur >= candidates.size()) {
            return;
        }

        if (target == 0) {
            ans.push_back(sub_ans);
        }

        // recursion relation
        for (int i = cur; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                sub_ans.push_back(candidates[i]);
                solve(candidates, target - candidates[i], sub_ans, i);
                sub_ans.pop_back();
            }
        }
    }
    // time complexity: O(n ^ (target) / M) // M: minium number in candidates
    // space complexity: O(target / M)
};