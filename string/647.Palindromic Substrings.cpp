class Solution {
public:
    int countSubstrings(string s) {        
        // method 1: brute force 
        // 1. find all substring
        // 2. check is palindromic or not
        
        auto Ispalindromic = [&](int l, int r) {
            while (l < r) {
                if(s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };
        
        int ans = 0;
        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (Ispalindromic(i, j)) ans += 1;
            }
        }
        return ans;
    }
    // time complexity: O(n^3)
    // space complexity: O(1)
};


class Solution {
public:
    int countSubstrings(string s) {        
        // method 2: dynamic programming 
        // 1. enumerate s[i], let each of them are the center point
        // 2. check how many palindromic can get for both odd & even length substring
        
        auto NumPalindromic = [&](int c1, int c2) {
            int num = 0;
            while (c1 >= 0 && c2 < s.size() && s[c1] == s[c2]) {
                num += 1;
                c1--;
                c2++;
            }
            return num;
        };
        
        int ans = 0;
        const int n = s.size();
        for (int i = 0; i < n; ++i) ans = ans + NumPalindromic(i, i) + NumPalindromic(i, i + 1);
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    int countSubstrings(string s) {        
        // method 3: dynamic programming
        // example: "aaab"
        
        //    j 0  1  2  3   
        // i    a  a  a  b   |
        // 0  a T  T  T  F   |
        // 1  a    T  T  F   |
        // 2  a       T  F   |
        // 3  b          T   v
        
        // axxa
        // i  j -> check substring (i + 1, j - 1) is substring
        
        // 1. create 2D dynamic programming memory [s.size(), s.size()] to store result (is palindromic or not)
        // 2. dp[i][j] = (s[i] == s[j]) and (d[i + 1][j - 1] if i - j > 3 else True)
        // 3. count how many true
        
        int ans = 0;
        
        const int col = s.size(), row = s.size();
        vector<bool> t(col, false); 
        vector<vector<bool>> dp(row, t);
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j]) {
                    if (i - j + 1 <= 3) dp[j][i] = true;
                    else { if (i > 1 && j < s.size() - 2) dp[j][i] = dp[j + 1][i - 1]; }
                }
                if (dp[j][i]) ans += 1;
            }
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(n^2)
};