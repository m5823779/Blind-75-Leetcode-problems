class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // method 1: brute force 
        const int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            set<char> st;
            for (int j = i; j < n; j++) {
                st.insert(s[j]);
                if (st.size() > 2) {
                    break;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(128)
};


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // method 2: sliding window
        int ans = 0;
        int distinct = 0;
        int l = 0;

        unordered_map<char, int> mp;
        for (int r = 0; r < s.size(); r++) {
            if (mp[s[r]] == 0) {
                distinct += 1;
            }
            mp[s[r]] += 1;

            while (distinct > 2) {
                mp[s[l]] -= 1;
                if (mp[s[l]] == 0) {
                    distinct -= 1;
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(128)
};