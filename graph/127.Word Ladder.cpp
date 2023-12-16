class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // method: BFS (Optimize)
        set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        int step = 0;
        q.push(beginWord);
        while (!q.empty()) {
            step++;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                string cur = q.front();
                q.pop();
                for (int i = 0; i < cur.size(); i++) {
                    for (int c = 'a'; c <= 'z'; c++) {
                        string newstring = cur;
                        newstring[i] = c;
                        if (dict.find(newstring) != dict.end()) {
                            if (newstring == endWord) return step + 1;
                            q.push(newstring);
                            dict.erase(newstring);
                        }
                    } 
                }
            }
        }
        return 0;
    }
    // time complexity: O(n * 26^m)
    // space complexity: O(n)
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // method: BFS (Bidirectional)
        set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        set<string> s1;
        set<string> s2;
        s1.insert(beginWord);
        s2.insert(endWord);
        int step = 0;
        while (!s1.empty() && !s2.empty()) {
            if (s1.size() > s2.size()) {
                swap(s1, s2);
            }
            step++;
            set<string> next;
            for (string word : s1) {
                for (int i = 0; i < word.size(); i++) {
                    for (int j = 'a'; j <= 'z'; j++) {
                        string newWord = word;
                        newWord[i] = j;
                        if (s2.find(newWord) != s2.end()) return step + 1;
                        if (dict.find(newWord) != dict.end()) {
                            dict.erase(newWord);
                            next.insert(newWord);
                        }
                    }
                }
            }
            s1 = next;
        }
        return 0;
    }
    // time complexity: O(n * 26^(m / 2))
    // space complexity: O(n)
};