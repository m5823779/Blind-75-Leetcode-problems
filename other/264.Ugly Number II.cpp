class Solution {
public:
    int nthUglyNumber(int n) {
        int* ugly = new int[n];
        ugly[0] = 1;
        int m = 1;
        int i = 0;  // 2
        int j = 0;  // 3
        int k = 0;  // 5
        while (m < n) {
            int tmp = min({ugly[i] * 2, ugly[j] * 3, ugly[k] * 5});
            if (tmp == ugly[i] * 2) i++;
            if (tmp == ugly[j] * 3) j++;
            if (tmp == ugly[k] * 5) k++;
            ugly[m] = tmp;
            m++;
        }
        return ugly[n - 1];
    }
};