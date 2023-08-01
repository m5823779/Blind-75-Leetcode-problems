class Solution {
public:
    bool rotateString(string s, string goal) {
        // method 1: brute force
        if (s.size() != goal.size()) return false;
        
        const int n = s.size();
        for (int i = 0; i <= n; i++) {
            if (i < n && goal[0] != s[i]) continue;
            string newStr = s.substr(i) + s.substr(0, i);
            if (newStr == goal) return true;
        }
        return false;
    }
};


class Solution {
public:
    bool rotateString(string s, string goal) {
        // method 2
        // abcdeabcde
        // cdeab
        if (s.size() != goal.size()) return false;
        string check = s + s;
        return check.find(goal) != string::npos;
    }
};
