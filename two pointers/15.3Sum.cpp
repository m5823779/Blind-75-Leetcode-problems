class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // method 1. brute force 
        // 1. sorting in order to remove duplilcate
        // 2. use hash set to store the ans (remove duplilcate)
        // 3. enumerate all <i, j, k>
        const int n = nums.size();
        set<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) ans.insert(ans.begin(), {nums[i], nums[j], nums[k]});
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
        // time complexity: O(n^3)
        // space complexity: O(1)
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // method 2. hash table
        // enumerate <i, j> find -(0 - nums[i] - nums[j]) in table or not
        // 1. sorting
        // 2. create hash table to store how many time for each element
        // 3. enumerate <i, j> pair
        //      if nums[i] = nums[i - 1]
        //      if nums[j] = nums[j - 1] => skip, to remove duplicate
        // 4. t = -(nums[i] + nums[j])
        // if hash table count >= 1 + (t = nums[j]) + (t == nums[j])

        const int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        map<int, int> counter;
        
        for (int i = 0; i < n; ++i) counter[nums[i]]++;
        
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
                
            for (int j = i + 1; j < n; ++j) {
                if (j - 1 != i && nums[j] == nums[j - 1]) continue;
                
                int t = -(nums[i] + nums[j]);
                if (t < nums[j]) continue;  // nums[i] <= nums[j] <= nums[k]
                if (counter.count(t) == 0) continue;
                if (counter[t] >= 1 + (t == nums[j]) + (t == nums[i])) {
                    ans.push_back( {nums[i], nums[j], t} );
                }
                
            }
        }
        return ans;
        // time complexity: O(n^2)
        // space complexity: O(n)
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // method 3. two pointer
        // 1. sorting
        // 2. enumerate nums[i]
        // 3. define two pointer <j, k>, such that i < j < k, and nums[i] + nums[j] + nums[k] = 0
        // 4. t = 0 - nums[i]
        // How to move <j, k> pointer 
        //      if (nums[j] + nums[k] > t) => too large => k--
        //      if (nums[j] + nums[k] < t) => too small => j++
        
        const int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            int k = n - 1;
            int t = 0 - nums[i];
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (j < k) {
                if (nums[j] + nums[k] > t) k--;
                else if (nums[j] + nums[k] < t) j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return ans;
        // time complexity: O(n^2)
        // space complexity: O(1)
    }
};