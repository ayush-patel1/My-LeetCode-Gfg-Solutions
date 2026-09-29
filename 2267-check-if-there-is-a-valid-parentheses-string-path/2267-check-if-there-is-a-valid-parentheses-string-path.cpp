class Solution {
public:
    int m, n;
    int dp[101][101][201];

    bool solve(int i, int j, int cur, vector<vector<char>>& grid) {
        if (i >= m || j >= n || cur < 0)
            return false;

        cur += (grid[i][j] == '(' ? 1 : -1);

        if (cur < 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return cur == 0;

        if (dp[i][j][cur] != -1)
            return dp[i][j][cur];

        return dp[i][j][cur] =
            solve(i + 1, j, cur, grid) ||
            solve(i, j + 1, cur, grid);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2)
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, grid);
    }
};