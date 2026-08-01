class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(int r, int c, int col, int oc, vector<vector<int>>& image) {
        image[r][c] = col;

        int n = image.size();
        int m = image[0].size();

        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                image[nr][nc] == oc) {
                dfs(nr, nc, col, oc, image);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc = image[sr][sc];

        if (oc == color)
            return image;

        dfs(sr, sc, color, oc, image);

        return image;
    }
};