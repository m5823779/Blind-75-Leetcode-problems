class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // method 1: two pointer
        // *-------------------------*
        //    *-----*
        //                 *-------* 
        // how many meeting is going ...
        // ^
        // 1  ^
        //    2     ^
        //          1
        //                 ^
        //                 2      ^
        //                        1 ^
        //                          0
        const int n = intervals.size();
        vector<int> start_time;
        vector<int> end_time;
        for (auto interval : intervals) {
            start_time.push_back(interval[0]);
            end_time.push_back(interval[1]);
        }
        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());
        
        int count = 0;
        int ans = 0;
        int i = 0;  // start time pointer
        int j = 0;  // end time pointer
        while (i < n) {
            if (start_time[i] < end_time[j]) {
                count++;
                i++;
                ans = max(ans, count);
            }
            else {
                count--;
                j++;
            }
        }
        return ans;
    }
    // time complexity: O(nlogn)
    // space complexity: O(n)
};