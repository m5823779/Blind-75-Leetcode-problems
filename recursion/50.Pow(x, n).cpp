class Solution {
public:
    double myPow(double x, int n) {
        // method 1: brute force (recursive)
        if (n == 0) return 1.0;
        else if (n > 0) return x * myPow(x, n - 1);
        else {
            return (1 / x) * myPow(x, n + 1);
        }
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    double myPow(double x, int n) {
        // method 1: brute force (iterative)
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double ans = 1.0;
        for (int i = 0; i < n; i++) {
            ans *= x;
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};


class Solution {
public:
    double myPow(double x, int n) {
        // method 2: recursive (optimize)
        if (n == 0) return 1.0;
        
        double tmp = myPow(x, n / 2);
        // odd
        if (n & 1) {
            if (n > 0) return tmp * tmp * x;
            else return tmp * tmp * (1 / x);
        }
        // even
        else {
            return tmp * tmp;
        }
    }
    // time complexity: O(log n)
    // space complexity: O(log n)
};