class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // method 1: two pointers
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        return max_profit;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};