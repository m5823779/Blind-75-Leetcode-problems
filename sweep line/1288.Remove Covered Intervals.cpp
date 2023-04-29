class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // method: sorting
        auto cmp = [](auto a, auto b){
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), cmp);

        int ans = intervals.size();
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= intervals[i - 1][1]) {
                intervals[i] = intervals[i - 1];
                ans -= 1;
            }
        }
        return ans;
    }
    // time complexity: O(nlogn)
    // space compleixty: O(1)
};


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int last_start = -1;
        int last_end = -1;
        int valid_interval = 0;
        for (int i = 0; i < intervals.size(); i++) {
            // no interval be covered
            if (intervals[i][0] > last_start && intervals[i][1] > last_end) {
                valid_interval += 1;
                last_start = intervals[i][0];
                last_end = intervals[i][1];
            }
            // exist covered interval
            else {
                last_end = max(last_end, intervals[i][1]);
            }
        }
        return valid_interval;
    }
    // time complexity: O(nlogn)
    // space compleixty: O(1)
};