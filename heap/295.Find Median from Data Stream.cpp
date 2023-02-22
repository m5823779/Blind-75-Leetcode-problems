class MedianFinder {
private:
    vector<int> nums;
public:
    // method 1: brute force
    MedianFinder() {}
    void addNum(int num) {
        if (nums.empty()) {
            nums.push_back(num);
            return;
        }

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == num) {
                nums.insert(nums.begin() + m, num);
                return;
            }
            else if (nums[m] > num) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        nums.insert(nums.begin() + l, num);
        // time complexity: O (n(n + logn)) = O(n^2)
    }
    
    double findMedian() {
        if (nums.size() & 1) return nums[nums.size() / 2];
        else {
            double v1 = nums[nums.size() / 2];
            double v2 = nums[nums.size() / 2 - 1];
            return (v1 + v2) / 2;
        }
        // time complexity: O(1)
    }
};


class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> small_part;  // max heap
    priority_queue<int, vector<int>, greater<int>> large_part;  // min heap
public:
    // method 2: heap
    MedianFinder() {} 
    void addNum(int num) {
        if (small_part.size() == large_part.size()) {
            if (small_part.empty()) {
                small_part.push(num);
                return;
            }
            if (!large_part.empty() && large_part.top() < num) {
                small_part.push(large_part.top());
                large_part.pop();
                large_part.push(num);
            }
            else {
                small_part.push(num);
            }
        }
        else {
            if (!small_part.empty() && small_part.top() > num) {
                large_part.push(small_part.top());
                small_part.pop();
                small_part.push(num);
            }
            else {
                large_part.push(num);
            }
        }
        // time complexity: O(nlog(n / 2))
        // space complexity: O(n)
    }
    
    double findMedian() {
        if (small_part.size() != large_part.size()) {
            return static_cast<double>(small_part.top());
        }
        else {
            return static_cast<double>(small_part.top() + large_part.top()) / 2;
        }
        // time complexity: O(1)
        // space complexity: O(1)
    }
};