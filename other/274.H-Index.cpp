class Solution {
public:
    int hIndex(vector<int>& citations) {
        // method 1: sorting
        const int n = citations.size();
        sort(citations.begin(), citations.end());
        int h_index = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (citations[i] >= n - i) {
                h_index++;
            }
            else break;
        }
        return h_index;
    }
    // time complexity: O(nlogn)
    // space complexity: O(1)
};