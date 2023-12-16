class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // method: BFS
        vector<vector<pair<int, int>>> graph(n);
        for (vector<int> f : flights) {
            graph[f[0]].push_back({ f[1], f[2] });
        }

        vector<int> price(n, INT_MAX);
        price[src] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;  // <price, city, hope>
        pq.push({0, src, k + 1});

        while (!pq.empty()) {
            auto [cur_price, cur_city, stop] = pq.top();
            pq.pop();

            if (cur_city == dst) return cur_price;
            if (stop > 0) {
                for (auto nxt : graph[cur_city]) {
                    int nxt_city = nxt.first;
                    int nxt_price = cur_price + nxt.second;
                    price[nxt_city] = nxt_price;
                    pq.push({nxt_price, nxt_city, stop - 1});
                }
            }
        }
        return -1;
    }
};