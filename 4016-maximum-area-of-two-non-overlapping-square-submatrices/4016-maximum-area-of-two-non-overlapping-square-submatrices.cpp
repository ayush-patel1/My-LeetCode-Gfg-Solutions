class Solution {
public:
    bool check(int k, vector<vector<int>>& dp) {
        int m = dp.size(), n = dp[0].size();

        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] >= k) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return maxRow - minRow >= k || maxCol - minCol >= k;
    }

    long long maxArea(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        int mx = 0;

        // First row
        for (int j = 0; j < n; j++) {
            if (mat[0][j] == 1) {
                dp[0][j] = 1;
                mx = 1;
            }
        }

        // First column
        for (int i = 0; i < m; i++) {
            if (mat[i][0] == 1) {
                dp[i][0] = 1;
                mx = 1;
            }
        }

        // Main DP
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],
                        dp[i][j - 1],
                        dp[i - 1][j - 1]
                    });

                    mx = max(mx, dp[i][j]);
                }
            }
        }

        int l = 1, r = mx, ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, dp)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return 1LL * ans * ans;
    }
};