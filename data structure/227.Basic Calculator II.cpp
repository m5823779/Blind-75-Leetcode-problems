class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char sign = '+';
        stack<int> sk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = 10 * num + (s[i] - '0');
            }

            if (i == s.size() - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (sign == '+') {
                    sk.push(num);
                }
                else if (sign == '-') {
                    sk.push(-num);
                }
                else if (sign == '*') {
                    int tmp = sk.top() * num;
                    sk.pop();
                    sk.push(tmp);
                }
                else {
                    int tmp = sk.top() / num;
                    sk.pop();
                    sk.push(tmp);
                }
                sign = s[i];
                num = 0;
            }
        }

        int ans = 0;
        while (!sk.empty()) {
            ans += sk.top();
            sk.pop();
        }
        return ans;
    }
};