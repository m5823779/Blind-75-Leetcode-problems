class Solution {
public:
    bool isValid(string s) {
        // method : stack
        // 1. create stack to store open parentheses
        // 2. create map to store pairs parentheses
        // 3. enumerate s[i]
        // 4. if s[i] is close parentheses, check is the valid open parentheses in stack
        //      return false, if not
        //      remove the latest element in stack
        // 5. push element into stack, if s[i] is open parentheses
        // 6. if there is empty in stack return true, else return false
        
        stack<char> c;
        
        map<char, char> m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';
        
        const int n = s.size();
        for (auto i : s) {
            if (m.find(i) != m.end()) { // find close parentheses
                if (!c.empty() && c.top() == m[i]) c.pop();
                else return false;
            }
            else c.push(i);
        }

        return c.empty();
    }
    // time complexity: O(n)
    // space complexity: O(n)
};