class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> stringTable(numRows);
        int row = 0;
        int direction = 1;
        for (char c : s) {
            stringTable[row] += c;
            if (row == 0) direction = 1;
            if (row == numRows - 1) direction = -1;
            row += direction;
        }

        stringstream ss;
        for (string tmp : stringTable) {
            ss << tmp;
        }
        return ss.str();
    }
};