class SparseVector {
public:
    vector<int> v1;
public:
    
    SparseVector(vector<int> &nums) {
        v1 = vector<int>(nums.begin(), nums.end());
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int n1 = v1.size();
        int n2 = vec.v1.size();
        if (n1 != n2) return INT_MIN;
        int dot = 0;
        for (int i = 0; i < n1; i++) {
            dot += v1[i] * vec.v1[i];
        }
        return dot;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);


class SparseVector {
public:
    unordered_map<int, int> mp;  // index, values
    SparseVector(vector<int> &nums) {
        // method: Hash map
        // cause sparse vectors [have many 0]
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                mp[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int dot = 0;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if (vec.mp.find((*it).first) != vec.mp.end()) {
                dot += ((*it).second * vec.mp[(*it).first]);
            }
        }
        return dot;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);