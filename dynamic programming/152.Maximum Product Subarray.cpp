class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // method 1. brute force
        // 1. enumerate pair <i, j> for right and left
        // 2. multiply all between i and j
        // i = 0, j =0, product = nums[0]
        // i = 0, j =1, product = nums[0] * nums[1]
        // i = 0, j =2, product = nums[0] * nums[1] * nums[2]
        // i = 0, j =k, product = nums[0] * nums[1] *   ...   * nums[k]

        const int n = nums.size();
        int ans = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int product = 1;
                for (int k = i; k <= j; ++k) {
                    product *= nums[k];
                }
                ans = max(ans, product);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // method 1. brute force (optimize)
        // 1. enumerate pair <i, j> for right and left
        // 2. multiply all between i and j
    
        // i = 0, j =0, product = nums[0]
        // i = 0, j =1, product = product * nums[1]
        // i = 0, j =2, product = product * nums[2]
        // i = 0, j =k, product = product * nums[k]

        const int n = nums.size();
        int ans = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            int product = 1;
            for (int j = i; j < n; ++j) {
                product *= nums[j];
                ans = max(ans, product);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // method 2. dynamic programming
        // [2, 3, -2, 4]
        // [2, 6, ]
        // 1. create vector "max_product" and "min_product" to store product
        // 2. max_product[i] = max(max_product[i - 1] * nums[i], min_product[i - 1] * nums[i], nums[i])
        //    min_product[i] = min(max_product[i - 1] * nums[i], min_product[i - 1] * nums[i], nums[i])

        const int n = nums.size();
        vector<int> max_product(n);
        vector<int> min_product(n);
        
        max_product[0] = nums[0];
        min_product[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            max_product[i] = max(max(max_product[i - 1] * nums[i], min_product[i - 1] * nums[i]), nums[i]);
            min_product[i] = min(min(max_product[i - 1] * nums[i], min_product[i - 1] * nums[i]), nums[i]);
        }

        return *max_element(max_product.begin(), max_product.end());
        // time complexity: O(n)
        // space complexity: O(n)
    }
};