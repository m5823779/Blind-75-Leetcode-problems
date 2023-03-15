class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // method 1: 
        // 1. enumerate intervals[i], and insert newInterval in correct position
        // 2. merge it (problem no.56)
        
        const int n = intervals.size();
        vector<vector<int>>::iterator it = intervals.begin();
        
        while (it != intervals.end()) {
            if ((*it)[0] < newInterval[0]) ++it;
            else break;
        }
        
        intervals.insert(it, newInterval);
        
        intervals = merge(intervals); 
        return intervals;
    }
    
private:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        const int n = intervals.size();
        
        for (int i = 0; i < n; ++i) {
            if (ans.empty() || ans.back()[1] < intervals[i][0]) ans.push_back(intervals[i]);
            else ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // method 2: 
        // enumerate intervals[i]
        // create "left" & "right" buffer
        // left.push_back(intervals[i]), if intervals[i][1] < newInterval[0]
        // right.push_back(intervals[i]), if intervals[i][0] > newInterval[1]
        // merge(intervals[i], newInterval), if other case
        // ans = {left, merge, right}
        
        const int n = intervals.size();
        
        vector<vector<int>> left;
        vector<vector<int>> right;
        
        int start = newInterval[0];
        int end = newInterval[1];
        
        for (int i = 0; i < n; ++i) {
            if (intervals[i][1] < start) left.push_back(intervals[i]);
            else if (intervals[i][0] > end) right.push_back(intervals[i]);
            else {
                start = min(intervals[i][0], start);
                end = max(intervals[i][1], end);
            }
        }
        
        vector<vector<int>> ans;
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), {start, end});
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};