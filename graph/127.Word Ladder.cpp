class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // method: BFS
        // 1. create hashset to store word list
        // 2. create hashmap to store the path from begin word to any
        // 3. create queue for BFS
        // 4. try to replace each char to 'a-z' 
        // 5. if new word is the end word return, if not add it to hashmap

        unordered_set<string> word_list(wordList.begin(), wordList.end());
        unordered_map<string, int> path;
        path[beginWord] = 1;

        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            string word = q.front();
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string new_word = word;
                for (int j = 'a'; j <= 'z'; j++) {
                    new_word[i] = j;

                    if (path.count(new_word)) { continue; } 
                    if (word_list.count(new_word) && new_word == endWord) { return path[word] + 1; }
                    if (word_list.count(new_word)) {
                        q.push(new_word);
                        path[new_word] = path[word] + 1;
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
        // method: BFS (Optimize)
        unordered_set<string> word_list(wordList.begin(), wordList.end());
        int path = 1;

        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            int s = q.size();
            for (int c = 0; c < s; c++) {
                string word = q.front();
                q.pop();

                if (word == endWord) { return path; }

                for (int i = 0; i < word.size(); i++) {
                    string new_word = word;
                    for (int j = 'a'; j <= 'z'; j++) {
                        new_word[i] = j;
                        if (word_list.count(new_word) && new_word != word) {
                            q.push(new_word);
                            word_list.erase(new_word);
                        }
                    }
                }
            }
            path += 1;
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
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (wordDict.find(endWord) == wordDict.end()) return 0;
        unordered_set<string> s1;
        unordered_set<string> s2;
        s1.insert(beginWord);
        s2.insert(endWord);
        int step = 0;

        while (!s1.empty() && !s2.empty()) {
            if (s1.size() > s2.size()) {
                swap(s1, s2);
            }
            step += 1;
            unordered_set<string> s;
            for (string word : s1) {
                for (int i = 0; i < word.size(); i++) {
                    for (int letter = 'a'; letter <= 'z'; letter++) {
                        string new_word = word;
                        new_word[i] = letter;
                        if (s2.count(new_word)) return step + 1;
                        if (wordDict.find(new_word) != wordDict.end()) {
                            wordDict.erase(new_word);
                            s.insert(new_word);
                        }
                    }
                }
            }
            s1 = s;
        }
        return 0;
    }
    // time complexity: O(n * 26^(m / 2))
    // space complexity: O(n)
};