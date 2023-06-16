class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // method 1: Greedy
        sort(boxTypes.begin(), boxTypes.end(), [](auto a, auto b){ return a[1] > b[1]; });
        
        int maxUnits = 0;
        for (vector<int> b : boxTypes) {
            if (truckSize - b[0] >= 0) {
                maxUnits += b[0] * b[1];
                truckSize -= b[0];
            }
            else {
                maxUnits += truckSize * b[1];
                break;
            }
        }
        return maxUnits;
    }
    // time complexity: O(nlogn)
    // space complexity: O(1)
};