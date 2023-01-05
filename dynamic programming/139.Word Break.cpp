class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // method 1: brute force 
        // example:
        // wordBreak("leecode") = 
        // wordBreak("") && inDict("leetcode") ||  - (x)
        // wordBreak("l") && inDict("eetcode") ||  - (x)
        // wordBreak("le") && inDict("etcode") ||  - (x)
        // wordBreak("lee") && inDict("tcode") ||  - (x)
        // wordBreak("leet") && inDict("code") ||  - (o)
        // wordBreak("leetc") && inDict("ode") ||  - (x)
        // wordBreak("leetco") && inDict("de") ||  - (x)
        // wordBreak("leetcod") && inDict("e") ||  - (x)
        // wordBreak("leetcode") && inDict("") ||  - (x)

        // wordBreak("leet") = 
        // wordBreak("") && inDict("leet") ||  - (o)
        // wordBreak("l") && inDict("eet") ||  - (x)
        // wordBreak("lee") && inDict("t") ||  - (x)
        // wordBreak("leet") && inDict("") ||  - (x)

        unordered_set<string> table(wordDict.begin(), wordDict.end());
        return wordBreak(s, table);
    }
private:
    bool wordBreak(string s, unordered_set<string>& table) {
        if (table.find(s) != table.end()) return true;

        bool tmp = false;
        for (int i = 0; i < s.size(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            tmp = tmp || (wordBreak(left, table) && table.find(right) != table.end()); 
        }
        return tmp;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // method 1: brute force (optimize) + memory
        // example:
        // wordBreak("leecode") = 
        // wordBreak("") && inDict("leetcode") ||  - (x)
        // wordBreak("l") && inDict("eetcode") ||  - (x)
        // wordBreak("le") && inDict("etcode") ||  - (x)
        // wordBreak("lee") && inDict("tcode") ||  - (x)
        // wordBreak("leet") && inDict("code") ||  - (o)
        // wordBreak("leetc") && inDict("ode") ||  - (x)
        // wordBreak("leetco") && inDict("de") ||  - (x)
        // wordBreak("leetcod") && inDict("e") ||  - (x)
        // wordBreak("leetcode") && inDict("") ||  - (x)

        // wordBreak("leet") = 
        // wordBreak("") && inDict("leet") ||  - (o)
        // wordBreak("l") && inDict("eet") ||  - (x)
        // wordBreak("lee") && inDict("t") ||  - (x)
        // wordBreak("leet") && inDict("") ||  - (x)

        unordered_set<string> table(wordDict.begin(), wordDict.end());
        return wordBreak(s, table);
    }
private:
    unordered_map<string, bool> memory; 
    bool wordBreak(string s, unordered_set<string>& table) {
        if (memory.find(s) != memory.end()) return memory[s];
        if (table.find(s) != table.end()) return memory[s] = true;
        

        for (int i = 0; i < s.size(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (wordBreak(left, table) && table.find(right) != table.end())
                return memory[s]=true; 
        }
        return memory[s] = false;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // method 2: dynamic programming
        const int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;

        for (int i = 1; i <= len; ++i) {
            for (string word : wordDict) {
                if (word.size() <= i && word == s.substr(i - word.size(), word.size()) && dp[i - word.size()]) 
                    dp[i] = true;
            }
        }
        return dp.back();
    }
    // time complexity: O(n * m)
    // space complexity: O(n)
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // method 2: dynamic programming
        const int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; --i) {
            for (string word : wordDict) {
                if (n - i + 1 >= word.size() && s.substr(i, word.size()) == word && dp[i + word.size()]) {
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }
    // time complexity: O(n * m)
    // space complexity: O(n)
};


class Solution {
public:
    struct trieNode {
        bool isEnd;
        vector<trieNode*> child;
        trieNode () : isEnd(false), child(26, nullptr) {}
    };
    
    bool wordBreak(string s, vector<string>& wordDict) {
        // method 3: trie tree (prefix tree)
        // 1. generate trie tree
        // 2. depth first search traversal trie tree

        root = new trieNode();
        memo = vector<int>(s.size(), -1);

        for (string word : wordDict) {
            trieNode* cur = root;
            
            for (char c : word) {
                if (!cur->child[c - 'a']) {
                    cur->child[c - 'a'] = new trieNode();
                }
                cur = cur->child[c - 'a'];
            }
            cur->isEnd = true;
        }

        return dfs(s, 0);
    }
private:
    trieNode* root = nullptr;
    vector<int> memo;
    bool dfs(string s, int cur) {
        const int n = s.size();
        if (cur == n) return true;
        if (memo[cur] == 0) return false;

        trieNode* p = root;

        for (int i = cur; i < n; ++i) {
            if (p->child[s[i] - 'a']) {
                p = p->child[s[i] - 'a'];

                if (p->isEnd && dfs(s, i + 1)) {
                    return true;
                }
            }
            else {
                break;
            }
        } 
        return memo[cur] = false;
    }

    // time complexity: O(wl) to generate trie + O(nl)
    // space complexity: O(wl)
    // n: s length
    // w: dic length
    // l: longest string length in dict
};