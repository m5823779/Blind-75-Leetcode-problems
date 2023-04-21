class Solution {
public:
    string smallestSubsequence(string s) {
        // method: monotonic stack
        const int n = s.size();

        map<char, int> last_appear;
        for (int i = 0; i < n; i++) {
            last_appear[s[i]] = i;
        }

        set<char> in_stack;
        stack<char> sk;
        for (int i = 0; i < n; i++) {
            if (in_stack.find(s[i]) != in_stack.end()) {
                continue;
            }
            while (!sk.empty() && sk.top() >= s[i] && last_appear[sk.top()] > i) {
                in_stack.erase(sk.top());
                sk.pop();
            }
            in_stack.insert(s[i]);
            sk.push(s[i]);
        }

        string ans;
        while (!sk.empty()) {
            ans = sk.top() + ans;
            sk.pop();
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};