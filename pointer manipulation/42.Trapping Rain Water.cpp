class Solution {
public:
    int trap(vector<int>& height) {
        // method 1: Brute force
        const int n = height.size();
        int vol = 0;
        for (int i = 0; i < n; i++) {
            int left_max = *max_element(height.begin(), height.begin() + i  + 1);
            int right_max = *max_element(height.begin() + i, height.end());
            int h = min(left_max, right_max);
            vol += (h - height[i]);
        }
        return vol;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    int trap(vector<int>& height) {
        // method 2: Dynamic programming (prefix max)
        const int n = height.size();
        
        vector<int> left_most(n, 0);
        left_most[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_most[i] = max(left_most[i - 1], height[i]);
        }

        vector<int> right_most(n, 0);
        right_most[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_most[i] = max(right_most[i + 1], height[i]);
        }
        
        int vol = 0;
        for (int i = 0; i < n; i++) {
            vol += min(left_most[i], right_most[i]) - height[i];
        }
        return vol;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    int trap(vector<int>& height) {
        // method 3: monotonic stack
        const int n = height.size();
        int ans = 0;
        stack<int> s;  // store indices

        for (int cur = 0; cur < n; cur++) {
            while (!s.empty() && height[cur] > height[s.top()]) {  // find heigher bound, means lower bound can trap water
                int pre = s.top();
                s.pop();

                if (s.empty()) {  // if it doesn't have left bound, it cant trap the water
                    break;
                }
                int w = cur - s.top() - 1;

                int left_most = height[s.top()];
                int right_most = height[cur];
                int h = min(left_most, right_most) - height[pre];
                ans += w * h;
            }
            s.push(cur);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};