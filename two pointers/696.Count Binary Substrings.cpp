class Solution {
public:
    int countBinarySubstrings(string s) {
        // method: brute force 
        int ans = 0;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j += 2) {
                if (valid(s.substr(i, j - i + 1))) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
private:
    bool valid(string s) {
        int l = 0; 
        int r = s.size() - 1;
        while (l <= r) {
            if (s[l] == s[r]) return false;
            if (l - 1 >= 0 && s[l] != s[l - 1]) return false;
            if (r + 1 < s.size() && s[r] != s[r + 1]) return false;
            l++;
            r--;
        }
        return true;
    }
    // time complexity: O(n^3)
    // space complexity: O(1)
};


class Solution {
public:
    int countBinarySubstrings(string s) {
        // method: two pointer
        int ans = 0;
        int cur = 1;
        int pre = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cur += 1;
            }
            else {
                ans += min(pre, cur);
                pre = cur;
                cur = 1;
            }
        }
        return ans + min(pre, cur);
    }
    // time complexity: O(n)
    // space complexity: O(1)
};