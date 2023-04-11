class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // method 1: brute force DFS (depth first search)
        // 1. enumerate board
        // 2. DFS
        //      - if last char return true
        //      - if out of boundry or char not match return false
        //      - for visited cell, rewrite value
        //      - DFS (x+1, y), (x-1, y), (x, y+1), (x, y-1)
        
        vector<string> ans;
            
        m = board.size();
        n = board[0].size();
        
        for (const string& s : words) 
            if (exist(board, s)) 
                ans.push_back(s);
        return ans;
    }
    
private:
    int m, n;  
    
    bool exist(vector<vector<char>>& board, string s) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) 
                if (search(board, s, 0, i, j)) return true;
        return false;
    }
    
    bool search(vector<vector<char>>& board, string s, int d, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != s[d]) return false;
        if (d == s.size() - 1) return true;

        char tmp = board[x][y];
        board[x][y] = '.';
        
        bool exist = search(board, s, d+1, x+1, y) || 
                     search(board, s, d+1, x-1, y) ||
                     search(board, s, d+1, x, y+1) ||
                     search(board, s, d+1, x, y-1);
        
        board[x][y] = tmp;
        return exist;
    }
    
    // time complexity: O(mn*4^l) l: string length
    // space complexity: O(l)
};


// method 2: trie (prifix tree)
// 1. create trie, and add words into it
// 2. use DFS traversal on board

struct trieNode {
    bool isEnd;
    vector<trieNode*> child;
    string word;
    
    trieNode() : isEnd(false), child(26, nullptr) {};
    ~trieNode() {
        for (trieNode* c : child)
            if (c) delete c;
    }
};

class Solution {
private:
    trieNode* root = nullptr;
    
    void addWord (const string& w) {
        trieNode* cur = root;
        
        for (const char& c : w) {
            if (!cur->child[c - 'a']) 
                cur->child[c - 'a'] = new trieNode();
            
            cur = cur->child[c - 'a'];
        }
        cur->word = w;
        cur->isEnd = true;
    }
    
private:
    int m, n;
    
    void dfs (vector<vector<char>>& board, int x, int y, trieNode* cur, vector<string>& ans) {
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '.') return;
        if (!cur->child[board[x][y] - 'a']) return;
        
        cur = cur->child[board[x][y] - 'a'];
        
        if (cur->isEnd) {
            ans.push_back(cur->word);
            cur->isEnd = false;
        }
        
        char tmp = board[x][y];
        board[x][y] = '.';
        
        dfs(board, x+1, y, cur, ans);
        dfs(board, x-1, y, cur, ans);
        dfs(board, x, y+1, cur, ans);
        dfs(board, x, y-1, cur, ans);
        
        board[x][y] = tmp;
        return;
    }
    
public:
    // constructor
    Solution() { root = new trieNode(); }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {   
        for (const string& s : words) addWord(s);
        
        vector<string> ans;
        
        m = board.size();
        n = board[0].size();
        
        trieNode* cur = root;
        
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                dfs(board, i, j, cur, ans);

        return ans;
    }
    // time complexity: O(4^l)
    // space complexity: O(1)
};