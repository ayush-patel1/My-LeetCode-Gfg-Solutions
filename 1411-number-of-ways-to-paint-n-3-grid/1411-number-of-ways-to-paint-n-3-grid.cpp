class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<long long>> dp;

    // helper(i, p) = number of ways to paint rows from i to n-1
    // p = 0 → current row is ABC type (all 3 colors different)
    // p = 1 → current row is ABA type (1st and 3rd same)
    long long helper(int i, int p, int n) {
        // last row → nothing to decide further
        if (i == n - 1) return 1;

        if (dp[i][p] != -1) return dp[i][p];

        long long ans = 0;

        // From current row → next row
        // Next row can be:
        //   same pattern type → 2 valid color arrangements
        //   different pattern type → 2 valid color arrangements
        ans = (helper(i + 1, p, n) * 2 +
               helper(i + 1, 1 - p, n) * 2) % mod;

        // Extra case:
        // If current row is ABC,
        // there is ONE extra way to form ABC again
        if (p == 0)
            ans = (ans + helper(i + 1, p, n)) % mod;

        return dp[i][p] = ans;
    }

    int numOfWays(int n) {
        // dp[row][patternType]
        dp.assign(n, vector<long long>(2, -1));

        // First row:
        // ABC patterns = 6 color permutations
        // ABA patterns = 6 color permutations
        long long ans =
            (helper(0, 0, n) * 6 +   // start with ABC
             helper(0, 1, n) * 6) % mod; // start with ABA

        return ans;
    }
};
