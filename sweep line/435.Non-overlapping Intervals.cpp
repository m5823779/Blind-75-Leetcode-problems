class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // method: greedy
        // example 1.
        //  x------x
        //         x-------x
        // => no need to remove
        
        // example 2.
        // x-------x
        //    x--------x  => remove
        
        // exaple 3.
        // x--------x     => remove
        //    x---x
        
        // example 4.
        //      x------x
        // x--------------x  => remove
        
        // 1. sort by starting point
        // 2. enumerate intervals[i]
        // 3. counter += 1, if (intervals[i][0] < intervals[i - 1][1])
        // 4. intervals[i] = intervals[i - 1], if (intervals[i][1] > intervals[i - 1][1])
        
        // sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        sort(intervals.begin(), intervals.end());
             
        const int n = intervals.size();
        int ans = 0;
        
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                if (intervals[i][1] > intervals[i - 1][1]) intervals[i] = intervals[i - 1];
                ans += 1;
            }
        }
        return ans;
    }
    // time complexity: O(nlogn)
    // space complexity: O(1)
};