class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> pre;

        for (int i = 1; i <= numRows; i++) {
            vector<int> cur = solve(i, pre);
            ans.push_back(cur);
            pre = cur;
        }
        return ans;
    }
private:
    vector<int> solve(int level, vector<int>& pre) {
        vector<int> cur(level);
        cur[0] = 1;
        cur[level - 1] = 1;
        for (int i = 1; i < level - 1; i++) {
            cur[i] = pre[i] + pre[i - 1];
        }
        return cur;
    }
};