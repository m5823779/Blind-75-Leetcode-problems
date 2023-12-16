class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // method: Greedy
        vector<int> count(n);
        for (auto r : roads) {
            count[r[0]]++;
            count[r[1]]++;
        }

        sort(count.begin(), count.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (double)(i + 1) * count[i];
        }
        return ans;
    }
};