class Solution {
public:
    vector<vector<int>> adj;
    int max_cnt;

    int dfs(int node, int par) {
        int mx1 = 0, mx2 = 0;

        for (auto &it : adj[node]) {
            if (it == par) continue;

            int h = dfs(it, node);

            if (h > mx1) {
                mx2 = mx1;
                mx1 = h;
            } else if (h > mx2) {
                mx2 = h;
            }
        }

        max_cnt = max(max_cnt, mx1 + mx2);
        return 1 + mx1;
    }

    int getDiameter(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        max_cnt = 0;
        dfs(0, -1);
        return max_cnt;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;

        int d1 = getDiameter(n1, edges1);
        int d2 = getDiameter(n2, edges2);

        int r1 = (d1 + 1) / 2;
        int r2 = (d2 + 1) / 2;

        return max({d1, d2, r1 + r2 + 1});
    }
};
