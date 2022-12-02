class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // method 1. brute force
        const int n = nums.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            int product = 1;
            for (int j = 0; j <n; ++j) {
                if (i != j) product *= nums[j];
            }
            ans[i] = product;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // method 2. prefix sum: 可用於出現 “子數組和” 或者 “連續的子數組”
        // 1. create left & right, 
        //      left[i] = left[i - 1] * nums[i - 1]
        //      right[i] = right[i + 1] * nums[i + 1]
        // 2. enumerate i, which ans[i] = left[i] * right[i]
        const int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> ans(n); 
        
        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        
        for (int i = 0; i < n; ++i) {
            ans[i] = left[i] * right[i];
        }
  
        return ans;
        // time complexity: O(n)
        // space complexity: O(n)
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // method 2. prefix sum (simple version)
        // 1. create left & right, 
        //      left[i] = left[i - 1] * nums[i - 1]
        //      right[i] = right[i + 1] * nums[i + 1]
        // 2. enumerate i, which ans[i] = left[i] * right[i]
        const int n = nums.size();
        int left = 1;
        vector<int> right(n, 1);
        vector<int> ans(n); 
        
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        
        for (int i = 0; i < n; ++i) {
            ans[i] = left * right[i];
            left *= nums[i];
        }
  
        return ans;
        // time complexity: O(n)
        // space complexity: O(n)
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int len = nums.size();
        vector<int> prefix(len);
        vector<int> postfix(len);
        prefix[0] = nums[0];
        postfix[len - 1] = nums[len - 1];
        
        for (int i = 1; i < len; ++i) 
            prefix[i] = nums[i] * prefix[i - 1]; 
        
        for (int i = len - 2; i >= 0; --i)
            postfix[i] = nums[i] * postfix[i + 1];
        
        vector<int> ans(len);
        
        for (int i = 0; i < len; ++i)
            ans[i] = (i > 0 ? prefix[i - 1] : 1) * (i < len - 1 ? postfix[i + 1] : 1);
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};