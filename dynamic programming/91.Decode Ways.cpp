class Solution {
public:
    int numDecodings(string s) {
        // method 1: brute force
        // 1. Discuss two case: (pick one char) + (pick two char) if char <= "26"
        // 2. do recursive, return 1 when point to the last element, return 0 when char is '0'
        if (s.empty()) return 0;
        return solve(s, 0);
    }

private:
    int solve(string s, int cur) {
        if (cur == s.size()) return 1;
        if (s[cur] == '0') return 0;

        int case1 = solve(s, cur + 1);
        int case2 = 0;
        
        string tmp = s.substr(cur, 2);
        if (cur + 2 <= s.size() && tmp <= "26") {
            case2 += solve(s, cur + 2);
        }
        return case1 + case2;
    }
    // time complexity: O(2^n)
    // space complexity: O(n)
};