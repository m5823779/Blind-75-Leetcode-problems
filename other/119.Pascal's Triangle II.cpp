class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // method 1: brute force
        vector<int> row = {1};
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> new_row;

            new_row.push_back(1);
            for (int j = 0; j < row.size() - 1; j++) {
                new_row.push_back(row[j] + row[j + 1]);
            }
            new_row.push_back(1);
            
            row = new_row;
        }
        return row;
    }
};


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // method 2: optimize space
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        for (int i = 0; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
            row[i + 1] = 1;
        }
        return row;
    }
};