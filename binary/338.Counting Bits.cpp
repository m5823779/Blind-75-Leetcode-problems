class Solution {
public:
    vector<int> countBits(int n) {
        // method 1. brute force (mod version)
        vector<int> ans;
        
        for (int i = 0; i < n + 1; ++i) {
            int count = 0;

            int tmp = i;
            while(tmp) {
                count += (tmp % 2);
                tmp /= 2;
            }
            ans.push_back(count);
        }
        return ans;
        // time complexity: O(nlogn)
        // space complexity: O(1)
    }
};


class Solution {
public:
    vector<int> countBits(int n) {
        // method 1. brute force (bitwise version)
        vector<int> ans;
        
        for (int i = 0; i < n + 1; ++i) {
            int count = 0;

            int tmp = i;
            while(tmp) {
                count += (tmp & 1);
                tmp = tmp >> 1;
            }
            ans.push_back(count);
        }
        return ans;
        // time complexity: O(nlogn)
        // space complexity: O(1)
    }
};


class Solution {
public:
    vector<int> countBits(int n) {
        // method 2. dynamic programming
        // 0 -> 0000    dp[0] = 0
        // 1 -> 0001    dp[1] = 1
        // ----------------
        // 2 -> 0010    dp[0] + 1 = dp[2]
        // 3 -> 0011    dp[1] + 1 = dp[3]
        // ----------------
        // 4 -> 0100    dp[0] + 1 = dp[4]
        // 5 -> 0101    dp[1] + 1 = dp[5]  
        // 6 -> 0110    dp[2] + 1 = dp[6]
        // 7 -> 0111    dp[3] + 1 = dp[7]
        // ---------------- 
        // 8 -> 1000    dp[0] + 1 = dp[8]
        // 9 -> 1001    dp[1] + 1 = dp[9]
        //10 -> 1010    dp[2] + 1 = dp[10]
        //11 -> 1011    dp[3] + 1 = dp[11]
        //12 -> 1100    dp[4] + 1 = dp[12]
        //13 -> 1101    dp[5] + 1 = dp[13]
        //14 -> 1110    dp[6] + 1 = dp[14]
        //15 -> 1111    dp[7] + 1 = dp[15]
        // ----------------
        // offset = [1, 2, 4, 8, 16, 32 ...]
        // => dp[n] = 1 + dp[n - offset]
        

        vector<int> ans(n + 1);
        
        int offset = 1;
        ans[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            if (offset * 2 == i) offset = i;
            ans[i] = 1 + ans[i - offset];
        }
        return ans;
        // time complexity: O(n)
        // space complexity: O(1)
    }
};