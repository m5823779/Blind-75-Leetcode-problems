class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // method: recursion (backtracking, pick / not-pick approach) 
        sort(nums.begin(), nums.end());
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

        // pick
        sub_ans.push_back(nums[cur]);
        solve(nums, cur + 1, sub_ans);
        sub_ans.pop_back();
    
        while (cur + 1 < nums.size() && nums[cur] == nums[cur + 1]) {
            cur+=1;
        }

        // not pick
        solve(nums, cur + 1, sub_ans);
    }
    // time complexity: O(nlogn + n * 2^n)
    // space complexity: O(n)
};


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub_ans;
        solve(nums, 0, sub_ans);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int cur, vector<int> sub_ans) {
        ans.push_back(sub_ans);

        for(int i = cur; i < nums.size(); i++) {
            if (i - 1 >= cur && nums[i] == nums[i - 1]) {
                continue;
            }
            sub_ans.push_back(nums[i]);
            solve(nums, i + 1, sub_ans);
            sub_ans.pop_back();
        }
    }
    // time complexity: O(n * 2^n)
    // space complexity: O(n)
};