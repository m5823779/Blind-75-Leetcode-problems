class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // method: brute force
        vector<int> ans;

        const int n = nums1.size();
        for (int i = 0; i < n; i++) {
            int target = nums1[i];

            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == target) {
                    int next_greater = j + 1;
                    while (next_greater < nums2.size()) {
                        if (nums2[next_greater] > target) {
                            ans.push_back(nums2[next_greater]);
                            break;
                        }
                        next_greater++;
                    }

                    if (next_greater >= nums2.size()) {
                        ans.push_back(-1);
                    }
                    break;
                }
            }
        }
        return ans;
    }
    // time complexity: O(n * m)
    // space complexity: O(1)
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // method 2: Hash table
        unordered_map<int, int> mp;  // value, index
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        for (int i = 0; i < n2; i++) {
            mp[nums2[i]] = i;
        }
        
        vector<int> ans;
        for (int i = 0; i < n1; i++) {
            int target = nums1[i];
            int id = mp[target];

            while (id < n2 && nums2[id] <= target) {
                id += 1;
            }

            int res = (id >= n2) ? -1 : nums2[id];
            ans.push_back(res);
        }
        return ans;
    }
    // time complexity: O(n^2)
    // space complexity: O(n)
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // method 3: Monotonic stack (stack)
        // nums2[i], the first element greater than nums2[i]
        map<int, int> mp;
        stack<int> sk;
        for (int i = 0; i < nums2.size(); i++) {
            while (!sk.empty() && sk.top() < nums2[i]) {
                int tmp = sk.top();
                sk.pop();
                mp[tmp] = nums2[i];
            }
            sk.push(nums2[i]);
        }

        while (!sk.empty()) {
            int tmp = sk.top();
            sk.pop();
            mp[tmp] = -1; 
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
    // time complexity: O(m + n)
    // space complexity: O(n)
};