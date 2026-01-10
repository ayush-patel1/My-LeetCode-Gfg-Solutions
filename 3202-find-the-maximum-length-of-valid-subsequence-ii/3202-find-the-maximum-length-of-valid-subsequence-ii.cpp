class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        for (auto &it : nums) it %= k;

        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0;

        for (int v : nums) {
            // same value
            dp[v][v]++;
            ans = max(ans, dp[v][v]);

            // alternating
            for (int u = 0; u < k; u++) {
                if (u == v) continue;
                dp[v][u] = max(dp[v][u], dp[u][v] + 1);
                ans = max(ans, dp[v][u]);
            }
        }

        return ans;
    }
};
