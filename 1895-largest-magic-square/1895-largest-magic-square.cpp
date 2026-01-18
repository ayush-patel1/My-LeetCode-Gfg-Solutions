class Solution {
public:
    bool check(vector<vector<int>>& grid, int si, int sj, int k){
        int hsum = 0;
        for(int j = 0; j < k; j++)
            hsum += grid[si][sj + j];

        for(int i = 0; i < k; i++){
            int r = 0, c = 0;
            for(int j = 0; j < k; j++){
                r += grid[si + i][sj + j];
                c += grid[si + j][sj + i];
            }
            if(r != hsum || c != hsum) return false;
        }

        int d1 = 0, d2 = 0;
        for(int i = 0; i < k; i++){
            d1 += grid[si + i][sj + i];
            d2 += grid[si + i][sj + k - i - 1];
        }

        return d1 == hsum && d2 == hsum;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_k = 1;

        for(int k = 2; k <= min(n, m); k++){
            for(int i = 0; i + k <= n; i++){
                for(int j = 0; j + k <= m; j++){
                    if(check(grid, i, j, k))
                        max_k = k;
                }
            }
        }
        return max_k;
    }
};
