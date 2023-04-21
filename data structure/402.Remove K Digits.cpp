class Solution {
public:
    string removeKdigits(string num, int k) {
        // method: monotonic stack
        const int n = num.size();
        stack<char> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && num[i] < s.top() && k > 0) {
                s.pop();
                k -= 1;
            }
            s.push(num[i]);
        }

        while (k > 0) {
            s.pop(); 
            k--;
        }

        string ans = "" ;
        while (!s.empty()) {
            ans = s.top() + ans;
            s.pop();
        }

        int j = 0;
        while (j < ans.size() && ans[j] == '0') {
            j++;
        }
        ans.erase(0, j);

        return ans.empty() ? "0" : ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    string removeKdigits(string num, int k) {
        // method: monotonic stack
        const int n = num.size();
        stack<char> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && num[i] < s.top() && k > 0) {
                s.pop();
                k -= 1;
            }
            s.push(num[i]);
        }

        while (k > 0) {
            s.pop(); 
            k--;
        }

        string ans = "" ;
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }

        while (ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};