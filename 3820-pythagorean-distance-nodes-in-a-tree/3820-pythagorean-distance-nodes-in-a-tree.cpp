class Solution {
public:
    vector<vector<int>> adj;

    void dfs(vector<int>& dis, int node, int par) {
        for (auto& v : adj[node]) {
            if (v == par)
                continue;
            dis[v] = 1 + dis[node];
            dfs(dis, v, node);
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        adj.resize(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disX(n, 1e9), disY(n, 1e9), disZ(n, 1e9);

        disX[x] = 0;
        disY[y] = 0;
        disZ[z] = 0;

        dfs(disX, x, -1);
        dfs(disY, y, -1);
        dfs(disZ, z, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = disX[i], b = disY[i], c = disZ[i];
            vector<int> v = {a, b, c};
            sort(v.begin(), v.end());
            if (1LL * v[0] * v[0] + 1LL * v[1] * v[1] == 1LL * v[2] * v[2]) {
                ans++;
            }
        }

        return ans;
    }
};
