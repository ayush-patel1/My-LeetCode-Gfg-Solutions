class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int> ans(queries.size());
        unordered_map<int, int> ls;

        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int mx = *max_element(queries.begin(), queries.end());
        vector<int> ps(mx + 10, 0);

        for (int i = 0; i < logs.size(); i++) {
            int t = logs[i][1], s = logs[i][0];
            int l = t, r = min(mx, t + x);

            if (l > mx) continue;

            if (ls.find(s) != ls.end()) l = max(l, ls[s] + 1);

            if (l <= r) {
                ps[l]++;
                ps[r + 1]--;
            }

            ls[s] = max(ls[s], r);
        }

        for (int i = 1; i <= mx; i++) {
            ps[i] += ps[i - 1];
        }

        for (int i = 0; i < queries.size(); i++) {
            ans[i] = n - ps[queries[i]];
        }

        return ans;
    }
};