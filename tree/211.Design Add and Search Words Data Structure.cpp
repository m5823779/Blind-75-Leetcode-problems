class WordDictionary {
private:
    struct trieNode {
        bool isEnd;
        vector<trieNode*> child;
        
        trieNode() : isEnd(false), child(26, nullptr) {};
        ~trieNode() {
            for (auto c : child)
                if (c) delete c;
        }
    };
    
    trieNode* node;
    
public:
    WordDictionary() {
        node = new trieNode();
    }
    
    void addWord(string word) {
        trieNode* cur = node;
        
        for (char c : word) {
            if (!cur->child[c - 'a']) {
                cur->child[c - 'a'] = new trieNode();
            }
            cur = cur->child[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        trieNode* cur = node;
        return dfs(word, cur, 0);
    }
    
private:
    bool dfs(string& word, trieNode* cur, int i) {
        if (word.size() == i) return cur->isEnd;
        
        if (word[i] == '.') {
            for (trieNode* c : cur->child) {
                if (c && dfs(word, c, i + 1)) return true;
            }
            return false;
        }
        
        else 
            return cur->child[word[i] - 'a'] && dfs(word, cur->child[word[i] - 'a'], i + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */