class Solution {
public:
    int mySqrt(int x) {
        // method 1: brute force
        long n = 0;
        while (n * n <= x) {
            n++;
        }
        return (!n) ? 0 : n - 1;
    }
    // time complexity: O(sqrt(x))
    // space complexity: O(1)
};


class Solution {
public:
    int mySqrt(int x) {
        // method 1: brute force
        if (x <= 1) return x;
        for (long i  = 0; i <= x; i++) {
            if (i * i > x) return i - 1;
        }
        return 0;
    }
    // time complexity: O(sqrt(x))
    // space complexity: O(1)
};


// c++ "/" is slower than "*"
class Solution {
public:
    int mySqrt(int x) {
        // method 1: brute force
        if (x <= 1) return x;
        for (int i = 1; i <= x; i++) {
            if (i > x / i) { return i - 1; }
        }
        return -1;
    }
    // time complexity: O(sqrt(x))
    // space complexity: O(1)
};


class Solution {
public:
    int mySqrt(int x) {
        // method 2: binary search
        int l = 1;
        int r = x;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m == x / m) return m;
            else if (m > x / m) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return r;
    }
    // time complexity: O(logn)
    // space complexity: O(1)
};


class Solution {
public:
    int mySqrt(int x) {
        // method 3: newton's law
        // x(n+1) = x(n) - f(x(n)) / f'(x(n))
        // f(x(n)) = x^2 - a < 0
        // f'(x(n)) = 2x
        long long ans = x;
        while (ans * ans > x) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
    // time complexity: O(logn)
    // space complexity: O(1)
};