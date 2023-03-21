class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // method 1: depth first search (DFS)
        // 1. enumerate <i, j>
        // 2. recursive funtion solve(i, j, n) -> nth letters in word
        // solve(i, j, n)
        // return false, if i, j out of boundry
        // return false, if board[i, j] != word[n]
        // return true, if board[i, j] == word[n] and n is the last one
        // else solve(i - 1, j, n + 1)
        //      solve(i + 1, j, n + 1)
        //      solve(i, j - 1, n + 1)
        //      solve(i, j + 1, n + 1)
        
        const int h = board.size();
        const int w = board[0].size();
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (solve(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int n) {
        if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) return false;
        if (board[i][j] != word[n]) return false;
        if (board[i][j] == word[n] && n == word.size() - 1) return true;
        
        // to avoid re-use
        char tmp = board[i][j];
        board[i][j] = 0;
        
        bool result = (
        solve(board, word, i - 1, j, n + 1) ||
        solve(board, word, i + 1, j, n + 1) ||
        solve(board, word, i, j - 1, n + 1) ||
        solve(board, word, i, j + 1, n + 1));
        
        board[i][j] = tmp;
        
        return result;
    }
    // time complexity: O(m * n * 4 ^ l), l = word length
    // space complexity: O(m * n + l)
};