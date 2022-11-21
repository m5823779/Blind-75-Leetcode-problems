class Trie {
private:
    struct TrieNode {
        bool isEnd;
        vector<TrieNode*> child;
        
        TrieNode() : isEnd(false), child(26, nullptr) {};
        ~TrieNode() {
            for (auto c : child) {
                if (c) delete c;
            }
        }
    };
    
    std::unique_ptr<TrieNode> node;
    
public:
    Trie() {
        node = std::make_unique<TrieNode>();  // like dummy node
    }
    
    void insert(string word) {
        TrieNode* cur = node.get();
        
        for (auto w : word) {
            if (cur->child[w-'a'] == nullptr) {
                cur->child[w-'a'] = new TrieNode();
            }
            
            cur = cur->child[w-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = node.get();
        
        for (auto w : word) {
            if (cur->child[w-'a'] == nullptr) return false;
            cur = cur->child[w-'a'];
        }
        if (cur->isEnd) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = node.get();
        
        for (auto w : prefix) {
            if (cur->child[w-'a'] == nullptr) return false;
            cur = cur->child[w-'a'];
        }
        return true;
    }
    // time complexity: O(l)  length of words
    // space complexity: O(n * l^2)
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */