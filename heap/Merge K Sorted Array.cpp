// brute force
#include <iostream>

using namespace std;
#define N 4

void printArray(int* nums, int size) {
    cout << nums[0];
    for (int i = 1; i < size; i++) {
        cout << ", " << nums[i];
    }
}

void mergeTwoSorted(int* nums1, int* nums2, int s1, int s2, int* output) {
    int i = 0; 
    int j = 0;
    int k = 0;
    while (i < s1 && j < s2) {
        if (nums1[i] < nums2[j]) {
            output[k++] = nums1[i++];
        }
        else {
            output[k++] = nums2[j++];
        }
    }
    
    while (i < s1) {
        output[k++] = nums1[i++];
    }
    while (j < s2) {
        output[k++] = nums2[j++];
    }
}

void mergeKSorted(int nums[][N], int l, int r, int* output) {
    if (l == r) {
        for (int i = 0; i < N; i++) {
            output[i] = nums[l][i];
        }
        return;
    }   
    if (r - l == 1) {
        mergeTwoSorted(nums[l], nums[r], N, N, output);
        return;
    }
    
    int m = (l + r) / 2;
    int s1 = (m - l + 1) * N;
    int s2 = (r - m) * N;
    int* out1 = new int[s1];
    int* out2 = new int[s2];
    mergeKSorted(nums, l, m, out1);
    mergeKSorted(nums, m + 1, r, out2);
    mergeTwoSorted(out1, out2, s1, s2, output);
}

int main()
{
    int nums[][N] = {{1, 3, 4, 6}, {2, 5, 6, 7}, {1, 6, 8, 9}};
    int k = sizeof(nums) / sizeof(nums[0]);
    int* output = new int[k * N];
    mergeKSorted(nums, 0, k - 1, output);
    printArray(output, k * N);
    return 0;
}


// -------------------------------------------------------------------
// heap
#include <iostream>
#include <queue>

using namespace std;
#define N 4

void printArray(int* nums, int size) {
    cout << nums[0];
    for (int i = 1; i < size; i++) {
        cout << ", " << nums[i];
    }
}


void mergeKSorted(int nums[][N], int s, int* output) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    for (int i = 0; i < s; i++) {
        pq.push(make_pair(nums[i][0], 0));
    }
    
    int k = 0;
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        output[k++] = tmp.first;
        for (int i = 0; i < s; i++) {
            int cur_index = tmp.second;
            if (nums[i][cur_index] == tmp.first && cur_index < N) {
                pq.push(make_pair(nums[i][cur_index + 1], cur_index + 1));
            }
        }
    }
}

int main()
{
    int nums[][N] = {{1, 3, 4, 6}, {2, 5, 6, 7}, {1, 6, 8, 9}};
    int k = sizeof(nums) / sizeof(nums[0]);
    int* output = new int[k * N];
    mergeKSorted(nums, k, output);
    printArray(output, k * N);
    return 0;
}