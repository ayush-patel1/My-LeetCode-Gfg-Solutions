class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size(), m = grid[0].size();
        int ub = x + k - 1;
        for (int i = x; i <= (x + ub) / 2; i++) {
            for (int j = y; j < y + k; j++) {
                swap(grid[i][j], grid[ub - (i - x)][j]);
            }
        }
        return grid;
    }
};
