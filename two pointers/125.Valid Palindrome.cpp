class Solution {
public:
    bool isPalindrome(string s) {
        // method: two pointers
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && !isLetter(s[l])) {
                l++;
            }
            while (l < r && !isLetter(s[r])) {
                r--;
            }

            if ((s[l] + 32 - 'a') % 32 == (s[r] + 32 - 'a') % 32) {
                l++;
                r--;
            }
            else {
                return false;
            }
        }
        return true;
    }
private:
    bool isLetter(char c) {
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
        else if (c >= 'a' && c <= 'z') {
            return true;
        }
        else if (c >= '0' && c <= '9') {
            return true;
        }
        else {
            return false;
        }
    }
};