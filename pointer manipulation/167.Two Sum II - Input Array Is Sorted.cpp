class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // method: two pointers
        int l = 0; 
        int r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum > target) { r--; }
            else if (sum < target) { l++; }
            else {
                return {l + 1, r + 1};
            }
        }
        return {};
    }
    // time complexity: O(n)
    // space complexity: O(1)
};