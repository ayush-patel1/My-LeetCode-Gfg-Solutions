class Solution {
public:
    vector<int> vis;
    vector<vector<int>> adj;
    void dfs(int node) {
        vis[node] = 1;
        for (auto& it : adj[node]) {
            if (!vis[it]) {
                dfs(it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vis.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};