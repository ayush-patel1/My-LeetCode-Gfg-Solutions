class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int s) {
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) dp[i][i] = 0;

        for (auto &e : times) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            int t = e[2];
            dp[u][v] = min(dp[u][v], t);
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][k] != 1e9 && dp[k][j] != 1e9) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }

        s--;

        int ans = *max_element(dp[s].begin(), dp[s].end());
        return ans == 1e9 ? -1 : ans;
    }
};