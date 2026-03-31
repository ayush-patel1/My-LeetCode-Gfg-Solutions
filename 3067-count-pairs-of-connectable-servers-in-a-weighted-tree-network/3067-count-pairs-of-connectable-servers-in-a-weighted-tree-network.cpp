class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int s;

    int dfs(int u, int p, int d){
        int cnt = (d % s == 0);
        for(auto &it : adj[u]){
            int v = it.first, w = it.second;
            if(v == p) continue;
            cnt += dfs(v, u, d + w);
        }
        return cnt;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        s = signalSpeed;
        int n = edges.size() + 1;
        adj.resize(n);

        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> res(n);

        for(int i = 0; i < n; i++){
            vector<int> cnt;

            for(auto &it : adj[i]){
                int v = it.first, w = it.second;
                cnt.push_back(dfs(v, i, w));
            }

            int m = cnt.size();
            if(m == 0){
                res[i] = 0;
                continue;
            }

            vector<int> suf(m);
            suf[m-1] = cnt[m-1];

            for(int j = m-2; j >= 0; j--){
                suf[j] = suf[j+1] + cnt[j];
            }

            int sum = 0;
            for(int j = 0; j < m-1; j++){
                sum += cnt[j] * suf[j+1];
            }

            res[i] = sum;
        }

        return res;
    }
};