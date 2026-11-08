class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int res = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
            if (cnt > 1) {
                res += cnt;
                for (int j = 0; j < m; j++) {
                    vis[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int cnt = 0, visCnt = 0;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 1 && !vis[j][i]) {
                    cnt++;
                }
                if (grid[j][i] == 1 && vis[j][i]) { 
                    visCnt++;
                }
            }
            if (visCnt + cnt > 1) {
                res += cnt;
            }
        }

        return res;
    }
};
