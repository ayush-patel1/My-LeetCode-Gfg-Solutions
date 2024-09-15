class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>> dp(5, vector<long long>(n + 1, -1e9));

        for (int j = 0; j <= n; ++j) {
            dp[4][j] = 0;
        }

        for (int ind = 3; ind >= 0; --ind) {
            for (int i = n - 1; i >= 0; --i) {
                long long notTake = dp[ind][i + 1];
                long long take = (long long)a[ind] * (long long)b[i] + dp[ind + 1][i + 1];
                dp[ind][i] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};