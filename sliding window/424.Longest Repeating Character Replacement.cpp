class Solution {
public:
    int characterReplacement(string s, int k) {
        // method 1: brute force
        // 1. enumerate <i>
        // 2. create 26 dimension vector to count appearance times of each character
        // 3. declear pointer j, starting from i
        // 4. move pointer j, if (substring lenght - most appearance times character) <= k
        // 5. ans = max(ans, j - i + 1)
        
        const int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            // map<char, int> m;
            vector<int> count(26, 0);
            int j = i;
            
            while (j < n) {        
                count[s[j] - 'A']++;
                // if (j - i + 1 - (*max_element(m.begin(), m.end(), [](auto a, auto b){ return a.second < b.second; })).second <= k) {
                if ((j - i + 1) - *max_element(count.begin(), count.end()) > k) break;
                ans = max(ans, j - i + 1);
                j++;
            }
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(26)
};


class Solution {
public:
    int characterReplacement(string s, int k) {
        // method 2: sliding window
        // example
        // A  B  B  A  C, K = 1     substring - most appearance char
        // ij                       1 - 1 = 0
        // i  j                     2 - 1 = 1
        // i     j                  3 - 2 = 1
        // i        j               4 - 2 = 2 -> (x)
        //    i     j               3 - 2 = 1
        //    i        j            4 - 2 = 2 -> (x)
        //       i     j            3 - 1 = 2 -> (x)
        // ...
        
        // 1. create unorder map to count appearance times of each character
        // 2. declear pointer i & j
        //      move pointer i & minus 1 time in unorder map for ith character , if (substring - most appearance times character) > k
        //      move pointer j to last element
        // 3. ans = max(ans, j - i + 1)
        
        const int n = s.length();
        
        int ans = 0;
        int max_repeating = 0;
        
        unordered_map <char, int> counter;
        
        for (int i = 0, j = 0; j < n; ++j) {
            counter[s[j]] += 1;
            max_repeating = max(max_repeating, counter[s[j]]);
            
            if ((j - i + 1) - max_repeating > k) {
                counter[s[i]] -= 1;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(26)
};