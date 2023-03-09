class Solution {
public:
    bool isAnagram(string s, string t) {
        // method 1: hash map
        // 1. create two vectors, to count appears times of each character for both string
        // 2. check two vector is the same or not 
        if (s.length() != t.length()) return false;
        
        vector<int> s_counter(26);
        vector<int> t_counter(26);

        for (int i = 0; i < s.length(); ++i) {
            s_counter[s[i] - 'a']++;
            t_counter[t[i] - 'a']++;
        }
        
        for (int j = 0; j < s_counter.size(); ++j) {
            if (s_counter[j] != t_counter[j]) return false;
        }
        
        return true;
    }
    // time complexity: O(n + 26)
    // space complexity: O(2 * 26)
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        // method 1.1: hash map
        // 1. create two vectors, to count appears times of each character for both string
        // 2. check two vector is the same or not 
        if (s.length() != t.length()) return false;
        
        vector<int> s_counter(26);
        vector<int> t_counter(26);

        for (int i = 0; i < s.length(); ++i) {
            s_counter[s[i] - 'a']++;
            t_counter[t[i] - 'a']++;
        }
        
        return (s_counter == t_counter);
    }
    // time complexity: O(n + 26)
    // space complexity: O(2 * 26)
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        // method 2: hash map
        // 1. create two hash map, to count appears times of each character for both string
        // 2. check two vector is the same or not 
        if (s.length() != t.length()) return false;
        
        map<char, int> s_counter;
        map<char, int> t_counter;
        
        for (int i = 0; i < s.length(); ++i) {
            s_counter[s[i]]++;
            t_counter[t[i]]++;
        }
        
        for (int j = 0; j < s_counter.size(); ++j) {
            if (s_counter[j] != t_counter[j]) return false;
        }
        return true;
    }
    // time complexity: O(n + n)
    // space complexity: O(2 * n)
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        // method 3: sorting
        
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end(), [](char a, char b){return a < b;});
        sort(t.begin(), t.end(), [](char a, char b){return a < b;});
        return (s == t);
    }
    // time complexity: O(nlogn) ~ O(n^2)
    // space complexity: O(1)
};