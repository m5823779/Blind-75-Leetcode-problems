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


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // metjod 2: binary search
        int l1 = nums1.size();
        int l2 = nums2.size();
        if (l1 > l2) return findMedianSortedArrays(nums2, nums1);

        int total = l1 + l2;
        int half = (total + 1) / 2;

        int l = 0;
        int r = l1;
        while (l <= r) {
            int m1 = (l + r) / 2;
            int m2 = half - m1;

            int nums1_left = (m1 > 0) ? nums1[m1 - 1] : INT_MIN ; 
            int nums2_left = (m2 > 0) ? nums2[m2 - 1] : INT_MIN ;
            int nums1_right = (m1 < l1) ? nums1[m1] : INT_MAX ;
            int nums2_right = (m2 < l2) ? nums2[m2] : INT_MAX ;

            if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
                if (total % 2 == 0) {
                    double n1 = max(nums1_left, nums2_left);
                    double n2 = min(nums1_right, nums2_right);
                    return (n1 + n2) / 2;
                }
                return max(nums1_left, nums2_left);
            }
            
            // num1 pick too many
            else if (nums1_left > nums2_right) {
                r = m1 - 1;
            }

            // nums2 pick to many
            else {
                l = m1 + 1;
            }
        }
        return -1;
    }
    // time complexity: O(log( min(n, m) ))
    // space complexity: O(log( min(n, m) ))
};