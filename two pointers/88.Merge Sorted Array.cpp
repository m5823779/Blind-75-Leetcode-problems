class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // method 1: two pointers
        int i = nums1.size() - nums2.size() - 1;
        int j = nums2.size() - 1 ;

        for (int k = nums1.size() - 1; k >= 0; k--) {
            if (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) nums1[k] = nums1[i--];
                else nums1[k] = nums2[j--];
            }
            else if (i >= 0) nums1[k] = nums1[i--];
            else nums1[k] = nums2[j--];
        }
    }
    // time compleixity: O(n)
    // space complexity: O(1)
};