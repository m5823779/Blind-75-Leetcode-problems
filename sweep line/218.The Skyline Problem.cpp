class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // method: sweep line
        vector<vector<int>> skyline;
        for (vector<int> building : buildings) {
            skyline.push_back({building[0], building[2]});
            skyline.push_back({building[1], -building[2]});
        }
        auto cmp = [](auto a, auto b){ 
            if (a[0] == b[0]) { 
                return a[1] > b[1]; 
            } 
            else { 
                return a[0] < b[0];
            }
        };

        sort(skyline.begin(), skyline.end(), cmp);

        multiset<int> height;  // min -> max
        height.insert(0);  // height starting from 0
        int cur_h = 0;
        int last_h = 0;

        vector<vector<int>> ans;
        for (vector<int> s : skyline) {
            if (s[1] >= 0) height.insert(s[1]);
            else height.erase(height.find(-s[1]));

            cur_h = *height.rbegin();
            if (cur_h != last_h) {
                ans.push_back({ s[0], cur_h });
                last_h = cur_h;
            }
        }
        return ans;
    }
    // time complexity: O(nlogn)
    // space complexity: O(n)
};