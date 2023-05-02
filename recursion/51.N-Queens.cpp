class Solution {
private:
    vector<vector<string>> ans;
    vector<string> board;
public:
    vector<vector<string>> solveNQueens(int n) {
        // method: backtracking

        // make a chessboard
        string tmp;
        for (int i = 0; i < n; i++) {
            tmp += '.';
        }
        for (int i = 0; i < n; i++) {
            board.push_back(tmp);
        }

        // DFS starting from row = 0
        dfs(0, n);
        return ans;
    }
private:
    void dfs(int row, int n) {
        // last row has been finished, append the sub-answer to the answer
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // discuss put the queen on every column in specific row
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, n)) {
                // put the queen if valid
                board[row][col] = 'Q';
                // go next level
                dfs(row + 1, n);
                // backtracking
                board[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, int n) {
        // check are there any queen in the same columns
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') return false;
        }

        // check are there any queen in the same rows
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') return false;
        }

        int k = 1;
        // check top - left
        while (row - k >= 0 && col - k >= 0) {
            if (board[row - k][col - k] == 'Q') return false;
            k++;
        }
        k = 1;
        // check top - right
        while (row - k >= 0 && col + k < n) {
            if (board[row - k][col + k] == 'Q') return false;
            k++;
        }
        return true;
    }
    // time compleixty: O(n^n) -> (n!)
    // space complexity: O(n)  // depth: n
};