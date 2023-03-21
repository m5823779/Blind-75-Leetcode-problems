class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // method 1: pointer
        int l = 0;
        int t = l;
        
        int r = matrix[0].size() - 1;
        int b = r;

        while (l < r) {
            for (int i = 0; i < r - l; ++i) {
                // store left-top to tmp
                int tmp = matrix[t][l + i];
                
                // move left-bottom to left-top
                matrix[t][l + i] = matrix[b - i][l];
                
                // move right-bottom to left-bottom
                matrix[b - i][l] = matrix[b][r - i];
                    
                // move right-top to right-bottom
                matrix[b][r - i] = matrix[t + i][r];
                    
                // move left-top to right-top
                matrix[t + i][r] = tmp;
            }
            l += 1;
            r -= 1;
            
            t += 1;
            b -= 1;
        }
        // time complexity: O(n^2)
        // space complexity: O(1)
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // method 2: diagonal
        //  1  2  3       9  6  3       7  4  1
        //  4  5  6   =>  8  5  2   =>  8  5  2
        //  7  8  9       7  4  1       9  6  3
        const int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
            }
        }
        // reverse(matrix.begin(), matrix.end());
        Reverse(matrix.begin(), matrix.end());
    }
private:
    void Reverse(vector<vector<int>>::iterator start, vector<vector<int>>::iterator end) {
        for (auto s = start, e = end - 1; s < e; s++, e--) {
            swap(*s, *e);
        }
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // method 2: diagonal
        //  1  2  3       1  4  7       7  4  1
        //  4  5  6   =>  2  5  8   =>  8  5  2
        //  7  8  9       3  6  9       9  6  3
        const int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            // reverse(matrix[i].begin(), matrix[i].end());
            Reverse(matrix[i].begin(), matrix[i].end());
        }
    }
private:
    void Reverse(vector<int>::iterator start, vector<int>::iterator end) {
        auto s = start;
        auto e = end - 1;
        while (s < e) {
            swap(*s, *e);
            s++;
            e--;
        }
    }
};