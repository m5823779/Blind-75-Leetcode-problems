class Solution {
private:
    int m, n;
public:
    void solveSudoku(vector<vector<char>>& board) {
        // method: backtracking
        m = board.size();
        n = board[0].size();
        if (dfs(board)) {
            return;
        }
    }
private:
    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (valid(board, i, j, c)) {
                            board[i][j] = c;
                            if (dfs(board)) {
                                return true;
                            }
                            else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool valid(vector<vector<char>>& board, int x, int y, char c) {
        for (int j = 0; j < m; j ++) {
            if (board[x][j] == c) return false;
        }

        for (int i = 0; i < n; i++) {
            if (board[i][y] == c) return false;
        }

        int grid_x = (x / 3) * 3;
        int grid_y = (y / 3) * 3;
        for (int i = grid_x; i < grid_x + 3; i++) {
            for (int j = grid_y; j < grid_y + 3; j++) {
                if (board[i][j] == c) return false;
            }
        }
        return true;
    }
};