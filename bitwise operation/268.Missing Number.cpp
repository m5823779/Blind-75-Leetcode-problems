class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // method 1. brute force
        // 1. get length n
        // 2. add sum = 0 + 1 + ... + n
        // 3. enumerate nums[i], then sum = sum - nums[i]
        // 4. return left element
        const int n = nums.size();
        int sum = (0 + n) * (n + 1) / 2;
        
        for (int i = 0; i < n; ++i) {
            sum -= nums[i];
        }
        return sum;
        // time complexity: O(n)
		// space complexity: O(1)
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // method 2. hash table
        // 1. create hash set
        // 2. enumerate nums[i] and store it into set
        // 3. get length n, enumerate (n + 1) and check if it in set or not
        const int n = nums.size();
        set<int> s;
        
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
        }
        
        for (int i = 0; i <= n; ++i) {
            if (s.find(i) == s.end()) return i;
        }
        return 0;
        // time complexity: O(n)
		// space complexity: O(n)
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // method 3: cyclic sort
        nums.push_back(-1);
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (i != nums[i] && nums[i] != -1) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != nums[i]) {
                return i;
            }
        }
        return -1;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // method 3. bitwise operation (XOR formulate)
        // XOR
        // 0 ^ 0 = 0
        // a ^ 0 = a
        // 0 ^ a = a
        // a ^ a = 0
        
        // a ^ b ^ c = b ^ a ^ c
        // a ^ a ^ b = b
        
        const int n = nums.size();

        int XOR = 0;
        
        for (int i = 0; i < n; ++i) {
            XOR = XOR ^ nums[i];
        }
        
        for (int i = 0; i <= n; ++i) {
            XOR = XOR ^ i;
        }
        return XOR;
        // time complexity: O(n)
		// space complexity: O(1)
    }
};