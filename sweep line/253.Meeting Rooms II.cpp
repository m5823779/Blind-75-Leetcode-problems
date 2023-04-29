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


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // method 2: sweep line (vector)
        vector<pair<int, int>> bucket;
        for (vector<int>& interval : intervals) {
            bucket.push_back({interval[0], 1});
            bucket.push_back({interval[1], -1});
        }

        sort(bucket.begin(), bucket.end());
        int ans = 0;
        int room = 0;
        for (pair<int, int> p : bucket) {
            room += p.second;
            ans = max(ans, room);
        }
        return ans;
    }
    // time complexity: O(nlogn)
    // space complexity: o(2n)
};


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // method 2: sweep line (tree map)
        map<int, int> mp;
        for (vector<int>& interval : intervals) {
            mp[interval[0]] += 1;
            mp[interval[1]] += -1;
        }

        int ans = 0; 
        int room = 0;
        for (auto p : mp) {
            room += p.second;
            ans = max(ans, room);
        }
        return ans;
    }
};


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // method 3: heap
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){ return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> pq;
        int room = 0;
        for (auto i : intervals) {
            if (!pq.empty() && pq.top() <= i[0]) {
                pq.pop();
            }
            pq.push(i[1]);
            room = max(room, (int)pq.size());
        }
        return room;
    }
};