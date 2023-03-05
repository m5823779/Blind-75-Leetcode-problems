class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // method: brute force
        int l1 = nums1.size();
        int l2 = nums2.size();
        vector<int> merge(l1+ l2);
        int i = 0, j = 0, k = 0;
        while (i < l1 && j < l2) {
            if (nums1[i] < nums2[j]) {
                merge[k++] = nums1[i++];
            }
            else {
                merge[k++] = nums2[j++];
            }
        }

        while (i < l1) {
            merge[k++] = nums1[i++];
        }

        while (j < l2) {
            merge[k++] = nums2[j++];
        }

        if ((l1 + l2) & 1) {
            return (double)merge[(l1 + l2) / 2];
        }
        else {
            double n = merge[(l1 + l2) / 2];
            double m = merge[(l1 + l2) / 2 - 1];
            return (m + n) / 2;
        }
    }
    // time complexity: O(n + m)
    // space complexity: O(n + m)
};