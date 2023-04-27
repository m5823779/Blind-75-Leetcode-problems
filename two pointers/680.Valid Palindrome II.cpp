class Solution {
public:
    bool validPalindrome(string s) {
        // method: two pointer
        const int n = s.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                break;
            }
            l++;
            r--;
        }
        if (l >= r) return true;
        return solve(s, l + 1, r) || solve(s, l, r - 1);
    }
private:
    bool solve(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};