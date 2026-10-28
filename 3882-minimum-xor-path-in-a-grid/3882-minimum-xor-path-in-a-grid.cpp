class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(int r, int c, int xr, vector<vector<int>>& grid) {
        if (r == n - 1 && c == m - 1) return xr ^ grid[r][c];

        if (dp[r][c][xr] != -1) return dp[r][c][xr];

        // bottom
        int op1 = 1e9, op2 = 1e9;

        if (r + 1 < n)
            op1 = solve(r + 1, c, xr ^ grid[r][c], grid);

        if (c + 1 < m)
            op2 = solve(r, c + 1, xr ^ grid[r][c], grid);

        return dp[r][c][xr] = min(op1, op2);
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(1024, -1)));

        return solve(0, 0, 0, grid);
    }
};