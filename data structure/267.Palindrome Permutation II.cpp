class Solution {
public:
    vector<string> generatePalindromes(string s) {
        // method 1: brute force (backtracking) (time out)
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


class Solution {
public:
    vector<string> generatePalindromes(string s) {
        // method: backtracking
        vector<string> ans;
        string sub_ans;

        // step 1: check is palindrom permutation or not
        vector<int> counter(26, 0);
        // count frequency of each char
        for (char c : s) {
            // pass space
            if (c == ' ') continue;

            // uppercase -> lowercase (A -> a)
            int id = (c - 'a' + 32) % 32;
            counter[id]++;
        }

        // check frequency of appear times is odd number
        int appearOdd = 0;
        for (int i = 0; i < 26; i++) {
            // appear times is odd number
            if (counter[i] % 2) {
                appearOdd++;
                sub_ans.push_back(i + 'a');
                counter[i]--;
            }
        }
        if (appearOdd > 1) return {};
        
        // step 2: backtracking
        backtracking(s, counter, ans, sub_ans);
        return ans;
    }

    void backtracking(const string& s, vector<int>& counter, vector<string>& ans, string sub_ans) {
        if (sub_ans.size() == s.size()) {
            ans.push_back(sub_ans);
            return;
        }
        for (int i = 0; i < counter.size(); i++) {
            if (counter[i] == 0) continue;
            counter[i] -= 2;
            char addChar = (char)(i + 'a');
            backtracking(s, counter, ans, addChar + sub_ans + addChar);
            counter[i] += 2;
        }
    }
};