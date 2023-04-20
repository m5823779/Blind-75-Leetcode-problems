class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // method 1: brute force 
        vector<int> ans;
        const int n = temperatures.size();
        for (int i = 0; i < n; i++) {
            int day_warm = 0;
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    day_warm = j - i;
                    break;
                }
            }
            ans.push_back(day_warm);
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // method 2: monotonic stack
        const int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<int> s;  // index, cause we need calcuate how many day
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[i] >= temperatures[s.top()]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};