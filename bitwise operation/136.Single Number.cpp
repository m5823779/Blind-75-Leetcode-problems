class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // method: Hash table
        set<int> s;
        for (int n : nums) {
            if (s.find(n) != s.end()) {
                s.erase(n);
            }
            else {
                s.insert(n);
            }
        }
        return *s.begin();
    }
    // time complexity: O(n)
    // space complexity: O(n)
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // method: XOR bitwise 
        int XOR = 0;
        for (int n : nums) {
            XOR ^= n;
        }
        return XOR;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};