class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int minCost(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u,2*wt});
        }

        vector<int> dis(n, 1e9);
        dis[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0}); 

        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int d = it.first;
            int u = it.second;
            if (d > dis[u]) continue;

            for (auto e : adj[u]) {
                int v = e.first, wt = e.second;
                if (dis[v] > dis[u] + wt) {
                    dis[v] = dis[u] + wt;
                    pq.push({dis[v], v});
                }
            }
        }

        if (dis[n-1] == 1e9) return -1;
        return dis[n-1];
    }
};
