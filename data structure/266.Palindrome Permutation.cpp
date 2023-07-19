class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> counter(26, 0);
        int appearOnce = 0;
        for (char c : s) {
                if (c != ' ') {
                    int id = (c - 'a' + 32) % 32;
                    counter[id]++;
                    if (counter[id] % 2) appearOnce++;
                    else appearOnce--;
            }
        }
        return appearOnce <= 1;
    }
    // time complexity: O(n)
    // space complexity: O(26)
};