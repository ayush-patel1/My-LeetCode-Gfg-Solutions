class Solution {
public:
    vector<vector<int>> dp;

    int solve(int k, int n) {
        if (n == 0 || n == 1) return n;
        if (k == 1) return n;

        if (dp[n][k] != -1) return dp[n][k];

        int res = INT_MAX;
        int l = 1, r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int left = solve(k - 1, mid - 1);
            int right = solve(k, n - mid);

            int cur = 1 + max(left, right);
            res = min(res, cur);

            if (left < right)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return dp[n][k] = res;
    }

    int superEggDrop(int k, int n) {
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return solve(k, n);
    }
};