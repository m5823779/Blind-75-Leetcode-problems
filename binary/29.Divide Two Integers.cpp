class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MIN;

        int sign = 1;
        if ((dividend < 0) ^ (divisor < 0)) {
            sign = -1;
        }

        long a = abs(dividend);
        long b = abs(divisor);
        long ans = 0;

        while (a >= b) {
            long tmp = b;
            long mul = 1;
            while (a > (tmp << 1)) {
                tmp <<= 1;
                mul <<= 1;
            }
            a -= tmp;
            ans += mul;
        }
        
        ans *= sign;
        if (ans >= INT_MAX) return INT_MAX;
        else return (int)ans;
    }
    // time complexity: O(logn)
    // space complexity: O(1)
};