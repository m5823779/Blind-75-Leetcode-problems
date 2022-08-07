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