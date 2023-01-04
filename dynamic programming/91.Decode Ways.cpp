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


class Solution {
public:
    int numDecodings(string s) {
        // method 2: dynamic programming
        // 1. create dp array to store the decode way (sub-string end with index i in string s) 
        // 2. set basic case (substring "" have one decoding way)
        // 3. dp[i] = dp[i - 1] + dp[i - 2], if the char is not '0' and substring <= "26"

        const int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '0') {
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i - 1];
            }

            if (i - 2 >= 0 && s.substr(i - 2, 2) <= "26" && s[i - 2] != '0') {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
        // time complexity: O(n)
        // space complexity: O(n)
    }
};


class Solution {
public:
    int numDecodings(string s) {
        // method 2: dynamic programming
        // 1. create dp array to store decode way (substring start with index i to the end in string)
        // 2. set basic case (substring "" has one decoding way)
        // 3. enumerate from string length to 0
        // 4. dp[i] = dp[i + 1] + dp[i + 2], if char is not '0' and substring <= "26"

        const int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i + 1];
            }

            if (i + 1 < n && s.substr(i, 2) <= "26" && s[i] != '0') {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
        // time complexity: O(n)
        // space complexity: O(n)
    }
};