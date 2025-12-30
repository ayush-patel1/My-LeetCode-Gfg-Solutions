class Solution {
public:
    bool ok(int x, int y, vector<vector<int>>& g) {
        vector<int> vis(10, 0);
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9 || vis[v]) return false;
                vis[v] = 1;
            }
        }

        int prev = g[x][y] + g[x][y+1] + g[x][y+2];

        for (int i = 0; i < 3; i++) {
            int r = 0, c = 0;
            for (int j = 0; j < 3; j++) {
                r += g[x+i][y+j];
                c += g[x+j][y+i];
            }
            if (r != prev || c != prev) return false;
        }

        int d1 = g[x][y] + g[x+1][y+1] + g[x+2][y+2];
        int d2 = g[x][y+2] + g[x+1][y+1] + g[x+2][y];
        if (d1 != prev || d2 != prev) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                if (ok(i, j, grid)) ans++;
            }
        }
        return ans;
    }
};
