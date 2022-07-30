class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // method 1: brute force
        // 1. enumerate <i>, which i = [0, s.length())
        // 2. create 128 dimension vector "seen" to store appeare times for each char
        // 3. declear pointer j, which j = [i, s.length())
        // 4. move pointer j until current char have already appare
        // 5. ans = max(ans, j - 1)
        
        const int n = s.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            vector<int> seen(128);
            int j = i;
            
            while (j < n && !(seen[s[j]])) {
                // if (seen[s[j]] != 0) break;
                seen[s[j]]++;
                j++;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(128)
};