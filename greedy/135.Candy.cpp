class Solution {
public:
    int candy(vector<int>& ratings) {
        // method 1: Greedy
        const int n = ratings.size();
        // Each child must have at least one candy
        vector<int> candies(n, 1);

        // left -> right, check if right neighbor is larger
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                candies[i] =  candies[i - 1] + 1;
            }
        }
        
        // right -> left, check if left neighbor is larger
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                candies[i] =  candies[i + 1] + 1;
            }
        }

        int sum = 0;
        for (int candy : candies) sum += candy;
        return sum;
    }
    // time complexity: O(3n)
    // space complexity: O(1)
};


class Solution {
public:
    int candy(vector<int>& ratings) {
        // method 1: Greedy
        const int n = ratings.size();
        // Each child must have at least one candy
        vector<int> candies(n, 1);

        // left -> right, check if right neighbor is larger
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] =  candies[i - 1] + 1;
            }
        }
        
        // right -> left, check if left neighbor is larger
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] =  max(candies[i], candies[i + 1] + 1);
            }
        }

        int sum = 0;
        for (int candy : candies) sum += candy;
        return sum;
    }
    // time complexity: O(3n)
    // space complexity: O(1)
};