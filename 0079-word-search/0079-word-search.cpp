class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool solve(int r, int c, int idx, vector<vector<char>>& board, string &word) {
        if (r < 0 || r >= n || c < 0 || c >= m)
            return false;

        if (vis[r][c] || board[r][c] != word[idx])
            return false;

        if (idx == word.size() - 1)
            return true;

        vis[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (solve(nr, nc, idx + 1, board, word))
                return true;
        }

        vis[r][c] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vis.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};