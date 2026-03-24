class Solution {
public:
    const int mod = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int> v;
        for (auto &row : grid) {
            for (auto &x : row) v.push_back(x);
        }

        int n = v.size();
        vector<int> pre(n), suf(n);

        pre[0] = v[0]%mod;
        for (int i = 1; i < n; i++) {
            pre[i] = (1LL*pre[i-1] * v[i]) % mod;
        }

        suf[n-1] = v[n-1]%mod;
        for (int i = n-2; i >= 0; i--) {
            suf[i] = (1LL*suf[i+1] * v[i]) % mod;
        }
        for(auto &x:suf) cout<<x<<" ";
        if (n == 1) return {{v[0]}};

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) res[i] = suf[i+1];
            else if (i == n-1) res[i] = pre[i-1];
            else res[i] = (pre[i-1] * suf[i+1]) % mod;
        }

        int r = grid.size();
        vector<vector<int>> ans;

        int idx = 0;
        for (int i = 0; i < r; i++) {
            vector<int> t;
            int m = grid[0].size();
            for (int j = 0; j < m; j++) {
                t.push_back(res[idx++]);
            }
            ans.push_back(t);
        }

        return ans;
    }
};