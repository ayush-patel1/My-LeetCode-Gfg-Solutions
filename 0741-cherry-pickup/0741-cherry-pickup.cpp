class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n;

    int solve(int r1, int c1, int r2, vector<vector<int>>& grid) {
        int c2 = r1 + c1 - r2;

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1e9;
        }

        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];
        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int res = 0;
        if (r1 == r2 && c1 == c2) {
            res += grid[r1][c1];
        } else {
            res += grid[r1][c1] + grid[r2][c2];
        }

        int temp = max({
            solve(r1+1, c1, r2+1, grid),
            solve(r1, c1+1, r2, grid),
            solve(r1+1, c1, r2, grid),
            solve(r1, c1+1, r2+1, grid)
        });

        res += temp;

        return dp[r1][c1][r2] = res;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, solve(0, 0, 0, grid));
    }
};
