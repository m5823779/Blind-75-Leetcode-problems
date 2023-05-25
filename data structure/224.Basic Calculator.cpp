class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> sk;  // number, sign

        int current_number = 0;
        int res = 0;
        int sign = 1;
        set<char> sign_dict = {'+', '-'};

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                sk.push({res, sign});
                current_number = 0;
                res = 0;
                sign = 1;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                current_number = 10 * current_number + (s[i] - '0');
            }

            if (i == s.size() - 1 || sign_dict.find(s[i]) != sign_dict.end()) {
                res += (sign * current_number);
                if (s[i] == '+') sign = 1;
                if (s[i] == '-') sign = -1;
                current_number = 0;
            }

            if (s[i] == ')') {
                res += (sign * current_number);
                if (!sk.empty()) {
                    res *= sk.top().second;
                    res += sk.top().first;
                    sk.pop();
                }
                current_number = 0;
                sign = 1;
            }
        }
        return res;
    }
};