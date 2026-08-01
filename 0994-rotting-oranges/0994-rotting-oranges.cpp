class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        int n = grid.size(), m = grid[0].size();
        int tot = 0, days = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    tot++;
                } else if (grid[i][j] == 1) {
                    tot++;
                }
            }
        }

        int cnt = 0;

        while (!q.empty()) {
            int sz = q.size();
            cnt += sz;

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d];
                    int nc = c + dy[d];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }

            if (!q.empty())
                days++;
        }

        return cnt == tot ? days : -1;
    }
};