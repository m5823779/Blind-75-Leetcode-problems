class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // mehtod: recursion (backtracking)
        vector<int> sub_ans;
        solve(nums, sub_ans, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int> sub_ans, int cur) {
        ans.push_back(sub_ans);

        for (int i = cur; i < nums.size(); i++) {
            sub_ans.push_back(nums[i]);
            solve(nums, sub_ans, i + 1);
            sub_ans.pop_back();
        }
    }
    // time complexity: O(n * 2^n)  // 2^n combination, each need O(n) TC
    // space complexity: O(n)
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // mehtod: recursion (backtracking)
        vector<int> sub_ans;
        for (int c = 0; c <= nums.size(); c++) {
            solve(nums, c, 0, sub_ans); 
            // 3 choose 0
            // 3 choose 1
            // 3 choose 2
            // 3 choose 3
        }
        return ans;
    }

private:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int choose, int cur, vector<int> sub_ans) {
        // base case
        if (sub_ans.size() == choose) {
            ans.push_back(sub_ans);
            return;
        }

        // recursion relation
        for (int i = cur; i < nums.size(); i++){
            sub_ans.push_back(nums[i]);
            solve(nums, choose, i + 1, sub_ans);
            sub_ans.pop_back();
        }
    }
    // time complexity: O(n * 2^n)  // 2^n combination, each need O(n) TC
    // space complexity: O(n)
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // mehtod: recursion (backtracking)
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
    // time complexity: O(n * 2^n)  // 2^n combination, each need O(n) TC
    // space complexity: O(n)
};


