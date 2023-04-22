class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // method 1: brute force 
        const int n = heights.size();
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int w = j - i + 1;
                int h = *min_element(heights.begin() + i, heights.begin() + j + 1);
                max_area = max(max_area, w * h);
            }
        }
        return max_area;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // method 2: monotonic stack
        const int n = heights.size();
        int ans = 0;
        stack<int> s;  // store indices
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int pre = s.top();
                s.pop();
                int w = i - (s.empty() ? 0 : s.top() + 1);
                int h = heights[pre];
                ans = max(ans, w * h);
            }
            s.push(i);
        }

        while (!s.empty()) {
            int pre = s.top();
            s.pop();
            int w = n - (s.empty() ? 0 : s.top() + 1);
            int h = heights[pre];
            ans = max(ans, w * h);
        }
        return ans;
    }
    // time complexity: O(n)
    // space compleixty: O(1)
};