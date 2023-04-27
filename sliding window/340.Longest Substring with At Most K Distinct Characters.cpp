class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // method: brute force
        const int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                set<char> mp(s.begin() + i, s.begin() + j + 1);
                if (mp.size() <= k) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(n)
};


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // method 2: sliding window
        const int n = s.size();
        int ans = 0;
        int distinct = 0;
        map<char, int> counter;

        int l = 0;
        for (int r = 0; r < n; r++) {
            counter[s[r]]++;
            if (counter[s[r]] == 1) {
                distinct += 1;
            }

            while (distinct > k) {
                counter[s[l]] -= 1;
                if (counter[s[l]] == 0) {
                    distinct -= 1;
                } 
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};