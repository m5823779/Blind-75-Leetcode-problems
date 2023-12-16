class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int cur_max_time = neededTime[0];
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] != colors[i - 1]) {
                cur_max_time = neededTime[i];
            }
            // duplicate occur
            else {
                // remove the one need less time
                ans += min(cur_max_time, neededTime[i]);
                // update the maximum time avoid the next one still same color
                cur_max_time = max(cur_max_time, neededTime[i]);
            }
        }
        return ans;
    }
};