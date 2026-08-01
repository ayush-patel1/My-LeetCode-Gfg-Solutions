class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 1e9));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int r = node.first.first;
            int c = node.first.second;
            int d = node.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    ans[nr][nc] > d + 1) {
                    ans[nr][nc] = d + 1;
                    q.push({{nr, nc}, d + 1});
                }
            }
        }

        return ans;
    }
};