class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        vector<set<int>> anc(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                anc[v].insert(u);
                anc[v].insert(anc[u].begin(), anc[u].end());
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++)
            res[i] = vector<int>(anc[i].begin(), anc[i].end());
        return res;
    }
};