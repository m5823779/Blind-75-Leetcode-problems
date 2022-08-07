class Solution {
public:
    bool isPalindrome(string s) {
        // method: two pointer
        // 1. define two pointer
        // 2. enumerate two pointer
        //      move pointer, if s[left] = s[right]
        //      return false, if s[left] != s[right]
        // 3. check character is number or letters
        // 4. big letter and small letter are the same
        //      big letters and small letter in ASCII table difference of 32
        
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (!lettersOrnumbers(s[left])) left++;
            else if (!lettersOrnumbers(s[right])) right--;
            else {
                if ((s[right] + 32 - 'a') % 32 == (s[left] + 32 - 'a') % 32) {
                    left++;
                    right--;
                }
                else return false;
            }
        }
        return true;
    }
private: 
    bool lettersOrnumbers(char& c) {
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= 'a' && c <= 'z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};