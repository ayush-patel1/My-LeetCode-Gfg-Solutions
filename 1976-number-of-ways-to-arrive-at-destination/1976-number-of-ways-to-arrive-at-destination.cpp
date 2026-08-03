class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : roads) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dis(n, 1e18);
        vector<int> ways(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dis[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dis[u]) continue;

            for (auto [v, wt] : adj[u]) {
                if (dis[u] + wt < dis[v]) {
                    dis[v] = dis[u] + wt;
                    ways[v] = ways[u];
                    pq.push({dis[v], v});
                } else if (dis[u] + wt == dis[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};