class Solution {
public:
    vector<string> generatePalindromes(string s) {
        // method 1: brute force (backtracking)
        sort(s.begin(), s.end());
        vector<string> ans;
        vector<bool> used(s.size(), false);
        string p;
        perutation(s, used, p, ans);
        return ans;
    }

    void perutation(string s, vector<bool>& used, string& p, vector<string>& ans) {
        if (p.size() == s.size()) {
            if (isPalindrom(p)) {
                ans.push_back(p);
            }
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && !used[i - 1] && s[i] == s[i - 1]) continue;
            if (used[i]) continue;

            used[i] = true;
            p += s[i];
            perutation(s, used, p, ans);
            p.pop_back();
            used[i] = false;
        }
    }

    bool isPalindrom(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};