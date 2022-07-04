class Solution {
public:
    int climbStairs(int n) {
        // method 1. recursive 
        // n = 1 (1) => 1
        // n = 2 (1, 1) (2) => 2
        // n = 3 (1, 1, 1) (1, 2) (2, 1) => 3
        // n = 4 (1, 1, 1, 1) (1, 1, 2) (1, 2, 1) (2, 1, 1) (2, 2) => 5
        // n = 5 (1, 1, 1, 1, 1) (1, 1, 1, 2) (1, 1, 2, 1) (1, 2, 1, 1) (2, 1, 1, 1) (1, 2, 2), (2, 1, 2) (2, 2, 1) => 8
        // ...
        // 1, 2, 3, 5, 8 ... fibonacci
        
        if (n <= 2) return n;
        else return climbStairs(n - 1) + climbStairs(n - 2);
        // time complexity: O(2^n)
        // space complexity: O(1)
    }
};


class Solution {
public:
    int climbStairs(int n) {
        // method 2. dynamic programing 
        // n = 1 (1) => 1
        // n = 2 (1, 1) (2) => 2
        // n = 3 (1, 1, 1) (1, 2) (2, 1) => 3
        // n = 4 (1, 1, 1, 1) (1, 1, 2) (1, 2, 1) (2, 1, 1) (2, 2) => 5
        // n = 5 (1, 1, 1, 1, 1) (1, 1, 1, 2) (1, 1, 2, 1) (1, 2, 1, 1) (2, 1, 1, 1) (1, 2, 2), (2, 1, 2) (2, 2, 1) => 8
        // ...
        // 1, 2, 3, 5, 8 ... fibonacci
        
        vector<int> f(n + 1);
        f[0] = 1;
        f[1] = 2;
        
        for (int i = 2; i < n; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        
        return f[n - 1];
        // time complexity: O(n)
        // space complexity: O(n)
    }
};