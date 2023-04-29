class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // method: two pointers
        vector<vector<int>> result;

        const int n1 = firstList.size();
        const int n2 = secondList.size();
        
        sort(firstList.begin(), firstList.end());  // O(nlogn)
        sort(secondList.begin(), secondList.end());  // O(nlogn)

        int i = 0;
        int j = 0;
        
        while (i < n1 && j < n2) {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if (end - start >= 0) {
                result.push_back({start, end});
            }

            if (firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return result;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};