class Solution {
public:
    string reverseOnlyLetters(string s) {
        // method: two pointers
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && !isLetter(s[r])) {
                r--;
            }
            while (l < r && !isLetter(s[l])) {
                l++;
            }
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
private:
    bool isLetter(char c) {
        if (c >= 'A' && c <= 'Z') { return true; }
        else if (c >= 'a' && c <= 'z') { return true; }
        else { return false; }
    }
    // time complexity: O(logn)
    // space complexity: O(1)
};