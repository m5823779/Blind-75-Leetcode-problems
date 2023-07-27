class Solution {
public:
    int compress(vector<char>& chars) {
        // method 1: two pointers
        if (chars.empty()) return 0;
        int last = 0;  // last index
        int start = 0;  // the index which char is different from previous one
        int count = 1;  // count appear times

        for (int i = 1; i < chars.size(); i++) {
            // current char is different from previous one
            if (chars[i] != chars[i - 1]) {
                chars[last++] = chars[start];
                if (count > 1) {
                    string counter = to_string(count);
                    for (char c : counter) {
                        chars[last++] = c;
                    }
                }
                count = 1;
                start = i;
            }
            else count++;
        }

        chars[last++] = chars[start];
        if (count > 1) {
            string counter = to_string(count);
            for (char c : counter) {
                chars[last++] = c;
            }
        }
        return last;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};