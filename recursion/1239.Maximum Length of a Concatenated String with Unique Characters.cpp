class Solution {
public:
    int maxLength(vector<string>& arr) {
        string s;
        return dfs(arr, s, 0);
    }

    int dfs(vector<string>& arr, string s, int cur) {
        set<char> ss(s.begin(), s.end());
        if (ss.size() != s.size()) return 0;  // catain duplicate char
        int res = s.size();
        for (int i = cur; i < arr.size(); i++) {
            res = max(res, dfs(arr, s + arr[i], i + 1));
        }
        return res;
    }
};