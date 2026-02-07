class Solution {
public:
    vector<vector<int>> adj, tree;
    vector<int> ans;
    vector<vector<int>> pos;

    void build(int node, int parent, string &s, vector<int> &newPar) {
        int c = s[node] - 'a';

        if (!pos[c].empty()) newPar[node] = pos[c].back();
        else newPar[node] = parent;

        pos[c].push_back(node);

        for (int v : adj[node]) {
            if (v == parent) continue;
            build(v, node, s, newPar);
        }

        pos[c].pop_back();
    }

    int dfs(int node, int parent) {
        int sz = 1;
        for (int v : tree[node]) {
            if (v == parent) continue;
            sz += dfs(v, node);
        }
        ans[node] = sz;
        return sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();

        adj.assign(n, {});
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        vector<int> newPar(n);
        pos.assign(26, {});
        build(0, -1, s, newPar);

        tree.assign(n, {});
        for (int i = 1; i < n; i++) {
            tree[newPar[i]].push_back(i);
            tree[i].push_back(newPar[i]);
        }

        ans.assign(n, 0);
        dfs(0, -1);
        return ans;
    }
};
