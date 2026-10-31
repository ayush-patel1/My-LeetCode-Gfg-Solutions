class Solution {
public:
    int n, m;
    const int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;

    int solve(int r, int c, int dir, vector<vector<int>>& grid) {
        if(r < 0 || r >= n || c < 0 || c >= m) return 0;
        if(r == n-1 && c == m-1) return 1;
        if(dp[r][c][dir] != -1) return dp[r][c][dir];

        int val = grid[r][c];
        long long ans = 0;

        if(val == 1 && dir == 0) ans = solve(r+1, c, 1, grid) % MOD;
        else if(val == 1 && dir == 1) ans = solve(r, c+1, 0, grid) % MOD;

        if(val == 0) {
            ans = (ans + solve(r+1, c, 1, grid)) % MOD;
            ans = (ans + solve(r, c+1, 0, grid)) % MOD;
        }

        return dp[r][c][dir] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return solve(0, 0, 0, grid);
    }
};