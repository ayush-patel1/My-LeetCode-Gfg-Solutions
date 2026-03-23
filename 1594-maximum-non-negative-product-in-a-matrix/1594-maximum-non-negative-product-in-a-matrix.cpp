#define ll long long

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> max_dp(n, vector<ll>(m));
        vector<vector<ll>> min_dp(n, vector<ll>(m));

        max_dp[0][0] = min_dp[0][0] = grid[0][0];

        for (int j = 1; j < m; j++) {
            max_dp[0][j] = min_dp[0][j] = max_dp[0][j-1] * grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            max_dp[i][0] = min_dp[i][0] = max_dp[i-1][0] * grid[i][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                ll val = grid[i][j];
                ll mx = max(max_dp[i-1][j], max_dp[i][j-1]);
                ll mn = min(min_dp[i-1][j], min_dp[i][j-1]);
                max_dp[i][j] = max(val * mx, val * mn);
                min_dp[i][j] = min(val * mx, val * mn);
            }
        }

        ll result = max_dp[n-1][m-1];
        int MOD = 1e9+7;
        if (result < 0) return -1;
        return result % MOD;
    }
};