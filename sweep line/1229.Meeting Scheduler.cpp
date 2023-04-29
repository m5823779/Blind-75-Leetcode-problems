class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        // method: two pointers
        const int n1 = slots1.size();
        const int n2 = slots2.size();

        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int i = 0;
        int j = 0;

        while (i < n1 && j < n2) {
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if (end - start >= duration) {
                return {start, start + duration};
            }
            if (slots1[i][1] < slots2[j][1]) i++;
            else j++;
        }
        return {};
    }
    // time complexity: O(nlogn)
};