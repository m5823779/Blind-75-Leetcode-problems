class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // method 1: recursion
        return dfs(s, 0, wordDict);    
    }
private:
    vector<string> dfs(string s, int cur, vector<string>& wordDict) {
        if (cur == s.size()) return {""};
        vector<string> res;

        for (string word : wordDict) {

            if (s.substr(cur, word.size()) == word) {
                vector<string> sub_res = dfs(s, cur + word.size(), wordDict);
                
                for (string tmp : sub_res) {
                    res.push_back(word + (tmp.empty() ? "" : " " + tmp));
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // method 2: recursion + memorization
        return dfs(s, 0, wordDict);    
    }
private:
    unordered_map<string, vector<string>> memo;
    vector<string> dfs(string s, int cur, vector<string>& wordDict) {
        if (cur == s.size()) return {""};
        if (memo.find(s.substr(cur)) != memo.end()) return memo[s.substr(cur)];

        vector<string> res;
        for (string word : wordDict) {

            if (s.substr(cur, word.size()) == word) {
                vector<string> sub_res = dfs(s, cur + word.size(), wordDict);
                
                for (string tmp : sub_res) {
                    res.push_back(word + (tmp.empty() ? "" : " " + tmp));
                }
            }
        }
        return memo[s.substr(cur)] = res;
    }
};


class Solution {
public:
    struct trieNode {
        bool isEnd;
        string word;
        vector<trieNode*> child;
        trieNode () : isEnd(false), child(26, nullptr) {}
    };
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // method: trie tree (prefix tree)
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
            cur->word = word;
        }

        vector<string> result;
        dfs(s, 0, result);
        return ans;
    }
private:
    trieNode* root = nullptr;
    vector<int> memo;
    vector<string> ans;
     
    bool dfs(string s, int cur, vector<string> result) {
        const int n = s.size();

        if (cur == n) {
            string tmp;
            for (string s : result) {
                tmp += s + " ";
            }
            tmp.pop_back();
            ans.push_back(tmp);
            return true;
        }
        if (memo[cur] != -1) {
            return memo[cur];
        }

        trieNode* p = root;
        bool found = false;
        for (int i = cur; i < n; ++i) {
            if (p->child[s[i] - 'a']) {
                p = p->child[s[i] - 'a'];

                if (p->isEnd) {
                    result.push_back(p->word);
                    if (dfs(s, i + 1, result)) {
                        found = true;
                    }
                    result.pop_back();
                }
            }
            else {
                break;
            }
        } 

        if (found == false) {
            memo[cur] = found;
        }
        return found;
    }
};