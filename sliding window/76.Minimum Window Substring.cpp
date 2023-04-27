class Solution {
public:
    string minWindow(string s, string t) {
        // method 1: brute force
        unordered_map<char, int> s2;
        for (const char& c : t) {
            s2[c]++;
        }

        string ans;
        int min_len = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> s1;
            for (int j = i; j < s.size(); j++) {
                if (s2.count(s[j]) && s2[s[j]] > s1[s[j]]) {
                    s1[s[j]]++;
                }
                if (j - i + 1 >= min_len) {
                    break;
                }
                if (s1 == s2 && j - i + 1 < min_len) {
                    min_len = j - i + 1;
                    ans = s.substr(i, min_len);
                }
            }
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(n)
};


class Solution {
public:
    string minWindow(string s, string t) {
        // method 1: brute force
        unordered_map<char, int> s2;
        for (const char& c : t) {
            s2[c]++;
        }

        string ans;
        int min_len = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> s1;

            for (int j = i; j < s.size(); j++) {
                if (s2.count(s[j])) {
                    s1[s[j]]++;
                }
                if (j - i + 1 >= min_len) {
                    break;
                }

                if (validSubstr(s1, s2)) {
                    min_len = j - i + 1;
                    ans = s.substr(i, min_len);    
                }
            }
        }
        return ans;
    }
private:
    bool validSubstr(unordered_map<char, int>& s1, unordered_map<char, int>& s2) {
        for (pair<char, int> p : s2) {
            if (s1[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }
    // time complexity: O(n^2)
    // space complexity: O(n)
};


class Solution {
public:
    string minWindow(string s, string t) {
        // method 2: sliding window
        unordered_map<char, int> remain;
        for (const char& c : t) {
            remain[c]++;
        }

        string ans = "";
        int valid = 0;
        int min_len = INT_MAX;
        
        int start = 0;
        int min_start = 0;
        int min_end = 0;

        for (int end = 0; end < s.size(); end++) {
            if (remain.find(s[end]) == remain.end()) {
                continue;    
            }

            remain[s[end]]--;
            if (remain[s[end]] == 0) {
                valid += 1;
            }

            while (start <= end && valid == remain.size()) {
                if (end - start + 1 < min_len) {
                    min_len = end - start + 1;
                    min_start = start;
                    min_end = end;
                }

                char tmp_char = s[start];
                start++;
                if (remain.find(tmp_char) == remain.end()) {
                    continue;
                }
                else {
                    remain[tmp_char]++;   
                    if (remain[tmp_char] > 0) {
                        valid -= 1;
                    }
                }
            }
        }
        if (min_len != INT_MAX) {
            ans = s.substr(min_start, min_end - min_start + 1);
        }
        
        return ans;
        // time complexity: O(n)
        // space complexity: O(n)
    }
};