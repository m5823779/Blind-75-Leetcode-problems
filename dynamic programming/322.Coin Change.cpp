
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // method 1: brute force (pick not-pick approach)
        int ans = util(coins, amount, 0);
        return ans == INT_MAX ? -1 : ans;
    }
private:
    int util(vector<int>& coins, int amount, int current) {
        if (current >= coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX; 

        int num_coin;
        int pick = util(coins, amount - coins[current], current);
        if (pick != INT_MAX) {
            pick += 1;
        }

        int nopick = util(coins, amount, current + 1);
        num_coin = min(pick, nopick);
        return num_coin;
    }
    // time complexity: O(2^n)
    // space complexity: O(amount)
};

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        int ans = INT_MAX;

        for (auto coin : coins) 
            if (coin <= amount) {
                int sub_res = coinChange(coins, amount - coin);
                if (sub_res != -1)
                    ans = min(ans, sub_res + 1);
            }
        
        return ans == INT_MAX ? -1 : ans;
	}
	// time complexity: O(amount^n)
	// space complexity: O(amount)
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // method 2: Recursive + Memorization
        memo = vector<int>(amount + 1, INT_MIN);
        return dfs(coins, amount); 
    }
private:
    vector<int> memo;
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (memo[amount] != INT_MIN) return memo[amount];

        int num_coins = INT_MAX;

        for (int coin : coins) {
            if (amount - coin >= 0) {
                int tmp = dfs(coins, amount - coin);
                if (tmp != -1) {
                    num_coins = min(num_coins, 1 + tmp);
                }
            }
        }
        return memo[amount] = (num_coins == INT_MAX) ? -1 : num_coins;
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // method 1. dynamic programming
		// [1, 3, 4, 5]
		// amount: 7
		//	dp[amount = 0] = 0
		//	dp[amount = 1] = 1
		//	dp[amount = 2] = 1 + dp[1]
		//	dp[amount = 3] = 1 + dp[2] / 1
		//	dp[amount = 4] = 1 + dp[3] / 1 + dp[1] / 1
		//	dp[amount = 5] = 1 + dp[4] / 1 + dp[2] / 1 + dp[1] / 1
		//	dp[amount = 6] = 1 + dp[5] / 1 + dp[3] / 1 + dp[2] / 1 + dp[1]
		//	dp[amount = 7] = 1 + dp[6] / 1 + dp[4] / 1 + dp[3] / 1 + dp[2]
		// =>
		//	dp[amount = 0] = 0
		//	dp[amount = 1] = 1
		//	dp[amount = 2] = 2
		//	dp[amount = 3] = 1
		//	dp[amount = 4] = 1
		//	dp[amount = 5] = 1
		//	dp[amount = 6] = 2
		//	dp[amount = 7] = min(1 + dp[6], 1 + dp[4], 1 + dp[3], 1 + dp[2])
		
		// 1. create dp table to store result
		// 2. enumerate a from 0 - amount
		// 3. enumerate coins[i]
		// 4. dp[a] = min(dp[a], 1 + dp[a - coins[i]])
		const int n = coins.size();
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		
		for (int a = 1; a <= amount; ++a) {
			for (int i = 0; i < n; ++i) {
				if (a - coins[i] >= 0)
					dp[a] = min(dp[a], 1 + dp[a - coins[i]]);
			}
		}
		
		
		return (dp[amount] != amount + 1) ? dp[amount] : -1;
		// time complexity: O(amount * len(coins))
		// space complexity: O(amount)
    }
};