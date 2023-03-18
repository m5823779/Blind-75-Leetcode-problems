class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //  method: iterative
        // 1. sorting
        // 2. enumerate intervals[i]
        // 3. merge(current, previous), if current[0] <= previous[1]
        // 4. push_back to ans, if ans = NULL or current[0] > previous[1]
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        const int n = intervals.size();
        
        for (int i = 0; i < n; ++i) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) ans.push_back(intervals[i]);
            else ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }
        return ans;
    }
    // time complexity: O(nlogn)
    // space complexity: O(n)
};