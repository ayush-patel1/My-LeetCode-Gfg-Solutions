class Solution {
public:
    double champagneTower(int poured, int r, int c) {
        double dp[101][101] = {};
        dp[0][0] = poured;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j <= i; j++) {
                double extra = max(0.0, dp[i][j] - 1);

                dp[i + 1][j] += extra / 2;
                dp[i + 1][j + 1] += extra / 2;
            }
        }

        return min(1.0, dp[r][c]);
    }
};