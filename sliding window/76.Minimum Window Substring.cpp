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
        map<char, int> mp;
        for (char c : t) mp[c]++;
        
        int satisify = 0;
        int l = 0;
        string ans = "";
        int len = INT_MAX;

        int start = 0;
        int min_start = 0;
        int min_end = 0;

        for (int r = 0; r < s.size(); r++) {
            if (mp.find(s[r]) == mp.end()) continue;
            mp[s[r]]--;
            if (mp[s[r]] == 0) {
                satisify++;
            }

            while (l <= r && satisify == mp.size()) {
                if (r - l + 1 <= len) {
                    len = r - l + 1;
                    min_start = l;
                    min_end = r;
                }

                if (mp.find(s[l]) != mp.end()) {
                    mp[s[l]]++;
                    if (mp[s[l]] > 0) satisify--;
                }
                l++;
            }
        }

        if (len != INT_MAX) {
            ans = s.substr(min_start, min_end - min_start + 1);
        }
        return ans;
        // time complexity: O(n)
        // space complexity: O(n)
    }
};