class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // method: DFS
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