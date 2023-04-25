class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // method 1: brute force 
        vector<int> output(length, 0);
        for (vector<int> update : updates) {
            for (int i = update[0]; i <= update[1]; i++) {
                output[i] += update[2];
            }
        }
        return output;
    }
    // time complexity: O(m * n)  m: len(updates), n : length
    // space complexity: O(1)
};


class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // method 2: prefix sum (sweep line / laze propagtion)
        vector<int> prefix_sum(length);
        for (vector<int>& update : updates) {
            prefix_sum[update[0]] += update[2];
            if (update[1] + 1 < length) {
                prefix_sum[update[1] + 1] -= update[2];
            }
        }

        for (int i = 1; i < length; i++) {
            prefix_sum[i] += prefix_sum[i - 1];
        }
        return prefix_sum;
    }
    // time complexity: O(n)
    // space compleixty: O(n)
};