class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // method 1: divide and conquer
        return divide(nums, 0, nums.size() - 1);
    }

private:
    int divide(vector<int>& nums, int s, int e) {
        // base case
        if (s >= e) return nums[s];

        // divide
        int m = (s + e) / 2;
        int left_majority = divide(nums, s, m);
        int right_majority = divide(nums, m + 1, e);

        // conquer
        if (left_majority == right_majority) return left_majority;
        int left_count = conquer(nums, left_majority, s, m);
        int right_count = conquer(nums, right_majority, m + 1, e);
        return left_count > right_count ? left_majority : right_majority;
    }

    int conquer(vector<int>& nums, int target, int l, int r) {
        int count = 0;
        for (int i = l; i <= r; i++) {
            if (nums[i] == target) count++;
        }
        return count;
    }
    // time complexity: O(nlogn) 
    // space complexity: O(logn)
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // method 2: hash table
        unordered_map<int, int> mp;
        const int n = nums.size();
        for (int num : nums) {
            mp[num]++;
            if (mp[num] >= (n + 1) / 2) {
                return num;
            }
        }
        return -1;
    }
    // time complexity: O(n)
    // space ceomplexity: O(n)
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // method 3: voting
        int counter = 0;
        int res = 0;
        for (int num : nums) {
            if (counter == 0) res = num;

            if (num == res) counter += 1;
            else counter -= 1;
        }
        return res;
    }
    // time complexity: O(n)
    // space ceomplexity: O(1)
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // method 4: sorting
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
    // time complexity: O(nlogn)
    // space ceomplexity: O(1)
};