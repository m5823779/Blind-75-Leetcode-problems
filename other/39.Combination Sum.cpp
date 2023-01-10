class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // method : recursion
        vector<int> sub_ans;
        solve(candidates, target, 0, sub_ans);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int cur, vector<int> sub_ans) {
        // base case
        if (target == 0) {
            ans.push_back(sub_ans);
        }
        if (target < 0) {
            return;
        }

        // recursion relation
        while (cur < candidates.size()) {
            sub_ans.push_back(candidates[cur]);
            solve(candidates, target - candidates[cur], cur, sub_ans);
            sub_ans.pop_back();
            cur++;
        }
        // time complexity: O(n ^ (target) / M) // M: minium number in candidates
        // space complexity: O(target / M)
    }
};