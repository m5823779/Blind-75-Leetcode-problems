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
public:
    // method 2: heap
    priority_queue<int, vector<int>, less<int>> small;  // max heap
    priority_queue<int, vector<int>, greater<int>> large;  // min heap
    MedianFinder() {}
    
    void addNum(int num) {
        // balance
        if (small.size() == large.size()) small.push(num);
        else large.push(num);

        // correct
        if (!large.empty() && large.top() < small.top()) {
            int tmp1 = large.top();
            int tmp2 = small.top();
            large.pop();
            small.pop();
            large.push(tmp2);
            small.push(tmp1);
        }
    }
    // time complexity: O(nlog(n / 2))
    // space complexity: O(n)
    
    double findMedian() {
        if (small.size() == large.size()) {
            int a = (double)small.top();
            int b = (double)large.top();
            return (a + b) / 2.0;
        }
        else return (double)small.top();
    }
    // time complexity: O(1)
    // space complexity: O(1)
};
