class SummaryRanges {
private:
    set<int> s;
public:
    SummaryRanges() { }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        vector<int> data(s.begin(), s.end());

        int i = 0;
        while (i < data.size()) {
            int start = data[i];
            while (i + 1 < data.size() && data[i + 1] - data[i] == 1) {
                i++;
            }
            res.push_back({start, data[i]});
            i++;
        }
        return res;
    }
};


class SummaryRanges {
private:
    vector<int> data;
public:
    SummaryRanges() { }
    
    void addNum(int value) {
        // insertion sort
        // int i = 0;
        // for (i = 0; i < data.size(); i++) {
        //     if (data[i] == value) return;
        //     if (data[i] >= value) break;
        // }
        // data.insert(data.begin() + i, value);

        // binary search
        // int l = 0; 
        // int r = data.size() - 1;
        // while (l <= r) {
        //     int m = l + (r - l) / 2;
        //     if (data[m] == value) return;
        //     else if (data[m] > value) {
        //         r = m - 1;
        //     }
        //     else {
        //         l = m + 1;
        //     }
        // }
        // data.insert(data.begin() + l, value);
        
        // binary search (using function)
        auto pos = lower_bound(data.begin(), data.end(), value);
        if (pos != data.end() && *pos == value) return;
        data.insert(pos, value);
    }
    // time complexity: O(logn)
    // space complexity: O(n)
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (int i = 0; i < data.size(); i++) {
            if (!res.empty() && data[i] - res.back()[1] == 1) {
                res.back()[1] = data[i];
            }
            else {
                res.push_back({data[i], data[i]});
            }
        }
        return res;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};