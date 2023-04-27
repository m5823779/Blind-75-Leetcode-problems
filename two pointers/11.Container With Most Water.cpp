class Solution {
public:
    int maxArea(vector<int>& height) {
        // method 1. brute force
        // 1. enumerate all pair <i, j>
        // 2. h = min(nums[i], nums[j])
        // 3. area = (j - i) * h
        const int n = height.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int h = min(height[i], height[j]);
                ans = max(ans, h * (j - i)); 
            }
        }
        return ans;
        // time complexity: O(n^2)
        // space complexity: O(1)
    }
};


class Solution {
public:
    int maxArea(vector<int>& height) {
        // method 1. two pointers
        // 1. define two pointers <l, r>, start with l = 0 and r = height.size() - 1
        // 2. area = (j - i) * min(height[l] * height[r])
        // 3. if (height[l] < height[r]) l++, else r--
        
        const int n = height.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        
        while (l < r) {
            int area = (r - l) * min(height[l], height[r]);
            ans = max(ans, area);
            
            if (height[l] < height[r]) l++;
            else r--;
        }

        return ans;
        // time complexity: O(n)
        // space complexity: O(1)
    }
};