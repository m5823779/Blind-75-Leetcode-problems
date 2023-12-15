class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // method 1: brute force (recursive)
        int edit = 0;
        return solve(s, 0, t, 0, edit);
    }

    bool solve(string s, int i, string t, int j, int edit) {
        if (i >= s.size() && j >= t.size()) return edit == 1;
        if (edit > 1) return false;
        if (i >= s.size()) return solve(s, i, t, j + 1, edit + 1);
        if (j >= t.size()) return solve(s, i + 1, t, j, edit + 1);

        if (s[i] == t[j]) return solve(s, i + 1, t, j + 1, edit);
        else return solve(s, i + 1, t, j + 1, edit + 1) || solve(s, i + 1, t, j, edit + 1) || solve(s, i, t, j + 1, edit + 1);
    }
};


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // method 2: two pointer
        if (s.size() > t.size()) swap(s, t);
        int diff = (int)t.size() - (int)s.size();

        if (diff > 1) return false;
        else if (diff == 1) {
            int i, j = 0;
            
            for (i = 0; i < s.size(); i++) {
                if (s[i] != t[i]) break;
            }
            j = i + 1;
            while (i < s.size()) {
                if (s[i++] != t[j++]) return false;
            }
            return j == t.size();
        }
        else {
            int numDiff = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != t[i]) numDiff++;
            }
            return numDiff == 1;
        }  
    }
    // time complexity: O(min(m, n))
    // space complexity: O(1)
};


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // method 2: two pointer
        if (s.size() < t.size()) swap(s, t);
        const int m = s.size();
        const int n = t.size();
        if (m - n > 1) return false;
        else if (m - n == 1) {
            int i;
            for (i = 0; i < n; i++) {
                if (t[i] != s[i]) break;
            }
            return s.substr(i + 1) == t.substr(i);
        }
        else {
            int diff = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != t[i]) diff++;
            }
            return diff == 1;
        }
    }
    // time complexity: O(min(m, n))
    // space complexity: O(1)
};