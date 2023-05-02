class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // method: backtracking
        vector<vector<int>> ans;
        vector<int> sub_ans;
        dfs(1, n, k, ans, sub_ans);
        return ans;
    }
private:
    void dfs(int start, int end, int k, vector<vector<int>>& ans, vector<int>& sub_ans) {
        if (sub_ans.size() == k) {
            ans.push_back(sub_ans);
        }
        for (int i = start; i <= end; i++) {
            sub_ans.push_back(i);
            dfs(i + 1, end, k, ans, sub_ans);
            sub_ans.pop_back();
        }
    }
    // time complexity: C(k, N) = (N!) / (N - K)!K!
    // space complexity: O(k)
};