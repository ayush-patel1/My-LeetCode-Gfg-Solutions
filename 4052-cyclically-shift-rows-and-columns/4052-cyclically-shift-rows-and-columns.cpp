class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for (int i = 0; i < n; i++) {
            int k = rowShift[i];

            while (k--) {
                int temp = grid[i][0];

                for (int j = 0; j < n - 1; j++) {
                    grid[i][j] = grid[i][j + 1];
                }

                grid[i][n - 1] = temp;
            }
        }

        for (int j = 0; j < n; j++) {
            int k = colShift[j];

            while (k--) {
                int temp = grid[0][j];

                for (int i = 0; i < n - 1; i++) {
                    grid[i][j] = grid[i + 1][j];
                }

                grid[n - 1][j] = temp;
            }
        }

        return grid;
    }
};