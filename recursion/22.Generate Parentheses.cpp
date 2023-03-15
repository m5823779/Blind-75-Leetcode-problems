class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string sub_ans = "(";
        solve(n, 1, 0, sub_ans);
        return ans;
    }
private:
    vector<string> ans;
    void solve(int n, int open, int close, string sub_ans) {
        if (open == n, close == n) {
            ans.push_back(sub_ans);
        }
        if (open < n) {
            solve(n, open + 1, close, sub_ans + "(");
        }
        if (close < n && close < open) {
            solve(n, open, close + 1, sub_ans + ")");
        }
    }
    // time complexity: O(2^n)
    // space complexity: O(n)
};