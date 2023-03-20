class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // method 1. brute force
        // reverse decimal system formula
        // ans = ans * 10 + n % 10
        // n /= 10
        
        // reverse binary system formula
        // ans = ans * 2 + n % 2
        // n /= 2
        
        //      equal to 
        
        // ans = (ans << 1) | (n & 1)
        // n = n >> 1
        
        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = ans * 2 + (n % 2);
            n /= 2;
        }
        return ans;
        // time complexity: O(1)
        // space complexity: O(1)
    }
};


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // method 2. bitwise operation
        // reverse decimal system formula
        // ans = ans * 10 + n % 10
        // n /= 10
        
        // reverse binary system formula
        // ans = ans * 2 + n % 2
        // n /= 2
        
        //      equal to 
        
        // ans = (ans << 1) | (n & 1)
        // n = n >> 1
        
        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }
        return ans;
        // time complexity: O(1)
        // space complexity: O(1)
    }
};