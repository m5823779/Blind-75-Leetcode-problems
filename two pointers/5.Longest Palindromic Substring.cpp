class Solution {
public:
    string longestPalindrome(string s) {
        // method 1: brute force
        // 1. find all substring
        // 2. check is palindrome or not
        int longest = 0;
        string ans;
        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (Ispalindrome(s, i, j) && j - i + 1 > longest) {
                    longest = max(longest, j - i + 1); 
                    // ans = s.substr(i, j - i + 1);
                    ans = GetSubstring(s, i, j);
                }
            }
        }
        return ans;
    }
private:
    bool Ispalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    string GetSubstring(string& s, int left, int right) {
        string sub_str = "";
        for (int i = left; i <= right; ++i) {
            sub_str.push_back(s[i]);
        }
        return sub_str;
    }
    // time complexity: O(n^3)
    // space complexity: O(1)
};


class Solution {
public:
    string longestPalindrome(string s) {
        // method 2: dynamic programming (two pointers)
        // 1. enumerate s[i], let it to be a center element
        // 2. check is palindrome or not
        
        // define function to find the maximum palindrome length
        auto fun = [&](int c1, int c2){
            while (c1 >= 0 && c2 < s.size() && s[c1] == s[c2]) {
                c1--;
                c2++;
            }
            return (c2 - c1 + 1) - 2;
        };
        
        int longest = 0;
        string ans = "";
        
        const int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            // int len = max(fun(s, i, i), fun(s, i, i + 1));
            int len = max(fun(i, i), fun(i, i + 1));
            if (len > longest) {
                longest = len;
                ans = s.substr(i - ((len - 1) / 2), len);
            }
        }
        return ans;
    }
// private: 
//     int fun(string& s, int c1, int c2) {
//         while (c1 >= 0 && c2 < s.size() && s[c1] == s[c2]) {
//             c1--;
//             c2++;
//         }
//         return (c2 - c1 + 1) - 2;
//     }
    // time complexity: O(n^2)
    // space complexity: O(1)
};