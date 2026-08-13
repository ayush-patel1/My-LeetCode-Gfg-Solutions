class Solution {
public:
    vector<vector<int>> vis;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(int r, int c, vector<vector<char>>& grid) {
        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < grid.size() &&
                nc >= 0 && nc < grid[0].size() &&
                !vis[nr][nc] && grid[nr][nc] == '1') {
                
                dfs(nr, nc, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis.assign(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};