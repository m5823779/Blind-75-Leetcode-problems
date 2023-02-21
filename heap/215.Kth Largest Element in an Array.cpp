class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // method 1: heap(priority queue)
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
        // time complexity: O(nlogn + klogn)
        // space complexity: O(n)
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // method 2: min heap (priority queue)
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
        // time complexity: O(nlogk)
        // space complexity: O(k)
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // method 3: quick select
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }
private: 
    int quickSelect(vector<int>& nums, int l, int r, int target) {
        int pivot = nums[r];
        int i = l - 1;  // last index which is lager than pivoit
        // lager than pivot / pivot / smaller than pivot
        for (int j = l; j < r; j++) {
            if (nums[j] > pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        i++;
        swap(nums[r], nums[i]);
        
        if (i == target) {
            return nums[i];
        }
        else if (i > target) {
            return quickSelect(nums, l, i - 1, target);
        }
        else {
            return quickSelect(nums, i + 1, r, target);
        }
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // method 3: quick select
        int left = 0;
        int right = nums.size() - 1;
        while (true) {
            int id = quickSelect(nums, left, right);
            if (id == k - 1) {
                return nums[id];
            }
            else if (id > k - 1) {
                right = id - 1;
            }
            else {
                left = id + 1;
            }
        }
    }
private:
    int quickSelect(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        int j = l;
        while (j < r) {
            if (nums[j] > pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
            j++; 
        }
        i++;
        swap(nums[i], nums[r]);
        return i;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};