/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        // method: sorting
        vector<Interval> free;
        vector<Interval> work;
        for (vector<Interval> employee : schedule) {
            for (Interval interval : employee) {
                work.push_back(interval);
            }
        }

        sort(work.begin(), work.end(), [](auto a, auto b){ return a.start < b.start; });
        
        int last_leave = work[0].end;
        for (int i = 1; i < work.size(); i++) {
            if (work[i].start > last_leave) {
                free.push_back(Interval(last_leave, work[i].start));
            }
            last_leave = max(last_leave, work[i].end);
        }
        return free;
    }
    // time compleixty: O(mnlog(mn))  m: number of employee, n: average number of interval of an employee
    // space complexity: O(1)
};