class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int h = img1.size();
        const int w = img1[0].size();
        int large_overlap = 0;

        for (int y_offset = -w + 1; y_offset < w; y_offset++) {
            for (int x_offset = -h + 1; x_offset < h; x_offset++) {

                int total = 0;
                for (int i = 0; i < w; i++) {
                    for (int j = 0; j < h; j++) {
                        if (i + y_offset >= 0 && i + y_offset < h && 
                            j + x_offset >= 0 && j + x_offset < w && 
                            img2[i][j] == 1 && img1[i + y_offset][j + x_offset] == 1) {
                            total += 1;
                        }
                    }
                }
                large_overlap = max(large_overlap, total);

            }
        }

        return large_overlap;
    }
    // time complexity: O(n^4)
    // space complexity: O(1)
};