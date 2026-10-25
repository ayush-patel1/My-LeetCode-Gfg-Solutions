class Solution {
public:
    int n, m;
    bool flag;
    vector<vector<int>> vis;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int i, int j, vector<vector<int>>& grid) {
        vis[i][j] = 1;

        if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            flag = false;

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < m &&
                grid[x][y] == 0 && !vis[x][y]) {
                dfs(x, y, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vis.assign(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    flag = true;
                    dfs(i, j, grid);

                    if (flag)
                        ans++;
                }
            }
        }

        return ans;
    }
};