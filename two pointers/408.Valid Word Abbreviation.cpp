class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        // method: two pointers
        int i = 0;  // word 指標
        int j = 0;  // abbr 指標
        int offset = 0;

        for (j = 0; j < abbr.size(); j++) {
            if (abbr[j] <= '9' && abbr[j] >= '0') {
                if (offset == 0 && abbr[j] == '0') return false;
                offset = offset * 10 + (abbr[j] - '0');
            }
            else {
                i += offset;
                offset = 0;

                if (abbr[j] != word[i]) return false;
                i++;
            }
        }
        return i + offset == word.size();
    }
};