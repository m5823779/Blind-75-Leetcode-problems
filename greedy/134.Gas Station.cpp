class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // method 1: brute force
        const int n = gas.size();
        for (int i = 0; i < n; i++) {
            int cur = i;
            int tank = gas[cur];
            
            while (tank >= cost[cur]) {
                tank -= cost[cur];
                cur++;
                cur = cur % n;
                if (cur == i) {
                    return i;
                }
                tank += gas[cur];
            }
        }
        return -1;
    }
    // time complexity: O(n^2)
    // space complexity: O(1)
};


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // method 1: brute force
        const int n = gas.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++) {
            diff[i] = gas[i] - cost[i];
        }
        for (int i = 0; i < n; i++) {
            if (diff[i] < 0) continue;

            int tank = 0;
            for (int j = 0; j < n; j++) {
                tank += diff[(i + j) % n];
                if (tank < 0) break;
            }
            if (tank >= 0) return i;
        }
        return -1;
    }
};


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // method 2: Greedy
        const int n = gas.size();
        int sum = 0;

        int tank = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];

            tank += gas[i];
            if (tank < cost[i]) {
                tank = 0;
                start = i + 1;
            }
            else tank -= cost[i];
        }
        return sum >= 0 ? start : -1;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};