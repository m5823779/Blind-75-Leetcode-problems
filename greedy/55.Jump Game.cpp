class Solution {
public:
    bool canJump(vector<int>& nums) {
        // method 1: brute force (recrusion)
       return solve(nums, 0); 
    }
private:
    bool solve(vector<int>& nums, int cur) {
        if (cur == nums.size() - 1) return true;
        if (cur >= nums.size() || nums[cur] == 0) return false;

        for (int i = nums[cur]; i > 0; --i) {
            if (solve(nums, cur + i)) 
                return true;
        }
        return false;
    }
    // time complexity: O(n^n)
    // space complexity: O(n)
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        // method 2: brute force (recrusion + memorization)
        visited = vector<int>(nums.size(), -1);
        return solve(nums, 0); 
    }
private:
    vector<int> visited;
    bool solve(vector<int>& nums, int cur) {
        if (cur == nums.size() - 1) return visited[cur] = true;
        if (cur >= nums.size() || nums[cur] == 0) return false;
        if (visited[cur] != -1) return visited[cur];

        for (int i = nums[cur]; i > 0; --i) {
            if (solve(nums, cur + i)) 
                return visited[cur] = true;
        }
        return visited[cur] = false;
    }
    // time complexity: O(2^n)
    // space complexity: O(n)
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        // method 3: dymnamic programming
        // 1. create dp array to store if start from index i can reach the target n - 1
        // 2. setting basic case dp[n - 1] = true (itself is target)
        // 3. enumerate i, which i represent start from i is it possible reach the target n - 1
        // 4. enumerate all possible reachable indexes when in index i 
        // 5. dp[i] = true, if dp[i + step]
         
        const int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; --i) {
            for (int step = nums[i]; step >= 1; --step) {
                if (i + step <= n - 1 && dp[i + step]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
        // time complexity: O(n^2)
        // space complexity: O(n)
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        // method 4. greedy
        // 1. set goal
        // 2. enumerate i (start from i)
        // 3. if i can reach the current goal, replace the goal to current node
        // 4. final if goal = 0, return true

        const int n = nums.size();
        int goal = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= goal - i) {
                goal = i;
            }
        }
        return goal == 0;
        // time complexity: O(n)
        // space complexity: O(1)
    }
};