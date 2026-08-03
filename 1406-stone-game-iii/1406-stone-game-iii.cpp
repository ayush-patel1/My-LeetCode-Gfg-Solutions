class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 4, 0); // dp[i] stores max score difference (Alice - Bob) starting at i

        for (int i = n - 1; i >= 0; --i) {
            int total = 0;
            dp[i] = INT_MIN; // we want to maximize this
            for (int x = 1; x <= 3 && i + x <= n; ++x) {
                total += stoneValue[i + x - 1]; // sum of x stones starting from i
                dp[i] = max(dp[i], total - dp[i + x]); // current sum - opponent's best response
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};