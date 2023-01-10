class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sub_ans;
        solve(candidates, target, 0, sub_ans);
        return {ans.begin(), ans.end()};
    }

private:
    set<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int cur, vector<int> sub_ans) {
        // base case
        if (target == 0) {
            ans.insert(sub_ans);
        }
        if (target < 0) {
            return;
        }

        // recursion relation
        for (int i = cur; i < candidates.size(); i++) {
            sub_ans.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, sub_ans);
            sub_ans.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
        for (int i = cur; i < candidates.size(); i++) {
            if ( i > cur && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sub_ans.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, sub_ans);
            sub_ans.pop_back();
        }
    }
};