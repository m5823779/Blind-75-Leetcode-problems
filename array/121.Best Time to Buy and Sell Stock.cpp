class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // method 1: brute force
        // 1. enumerate all pair (i, j)
		// 		0 <= i < j <= n - 1 
        // 2. find max { prices[j] - prices[i] }
        int ans = 0;
        const int n = prices.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
        
        // time complexity: O(n^2)
        // space complexity: O(1)
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // method 2: dynamic programming
        // 1. create min_price & max_profit array
        // 2. enumerate prices[i]
        // 3. keep track min price before prices[i]: min { min_price[i - 1], prices[i] }
        // 4. store max profit before prices[i]: max{ max_profit[i - 1], prices[i] - min_price[i] }

        const int n = prices.size();
        vector<int> min_prices(n);
        vector<int> max_profit(n);
        
        min_prices[0] = prices[0];
        max_profit[0] = 0;
        
        for (int i = 1; i < n; ++i) {
            min_prices[i] = min(min_prices[i - 1], prices[i]);
            max_profit[i] = max(max_profit[i - 1], prices[i] - min_prices[i]);
        }
        return max_profit[n - 1];
        // time complexity: O(n)
        // space complexity: O(n)
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // method 2_1: dynamic programming (reduce version)
        // 1. define min_price & max_profit
        // 2. enumerate prices[i]
        // 3. keep track min price before prices[i]: min { min_price, prices[i] }, which k <= i
        // 4. store max profit before prices[i]: max{ max_profit, prices[i] - min_price }, which k <= i

        const int n = prices.size();
        
        int min_prices = prices[0];
        int max_profit = 0;
        
        for (int i = 1; i < n; ++i) {
            min_prices = min(min_prices, prices[i]);
            max_profit = max(max_profit, prices[i] - min_prices);
        }
        return max_profit;
        // time complexity: O(n)
        // space complexity: O(1)
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // method 3: two pointer
        // 1. define left & right pointer (left: buy, right: sell)
        // 2. if buying days price > selling days price -> move left pointer
        // 3. if buying days price < selling days price -> calculate profit -> update to ans
        // 4. repeat step 2, 3, until right pointer reach the end of array
        const int len = prices.size();
        int l = 0;
        int r = l + 1;
        int ans = 0;
        
        while (r < len) {
            if (prices[l] > prices[r]) {
                l++;
                r = l + 1;
            }
            else {
                ans = max(ans, prices[r] - prices[l]);
                r++;
            }
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};