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
        // case 1
        //      *-------*
        // *---*
        // case 2
        //      *-------*
        //                 *---*
        // case 3
        //      *-------*
        //        *----*
        const int n = intervals.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                ans.insert(ans.end(), intervals.begin() + i, intervals.end());
                return ans;
            }
            else if (newInterval[0] > intervals[i][1]) {
                ans.push_back(intervals[i]);
            }
            else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
        // time complexity: O(n)
        // spacec complexity: O(1)
    }
};