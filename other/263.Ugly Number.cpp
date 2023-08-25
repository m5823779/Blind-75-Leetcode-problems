class Solution {
public:
    bool isUgly(int n) {
        // method 1: math
        // n = 2^i * 3^j * 5^k
        if (n <= 0) return false;
        if (n == 1) return true;
        bool result = false;
        if (n % 2 == 0) result |= isUgly(n / 2);
        if (n % 3 == 0) result |= isUgly(n / 3);
        if (n % 5 == 0) result |= isUgly(n / 5);
        return result;
    }
};


class Solution {
public:
    bool isUgly(int n) {
        // method 1: math
        // n = 2^i * 3^j * 5^k
        if (n <= 0) return false;
        vector<int> factor = {2, 3, 5};
        for (int f : factor) {
            while (n % f == 0) n /= f;
        }
        return n == 1;
    }
};